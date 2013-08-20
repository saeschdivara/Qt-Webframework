#include "AbstractWebsite.h"
#include "private/AbstractWebsite_p.h"

#include "internationalisation/I18nManager.h"
#include "page/InteractivePageInterface.h"
#include "page/SecureContentInterface.h"
#include "page/resource/AbstractResource.h"
#include "page/resource/ImageResource.h"

#include <headers.h>
#include <httpserverresponse.h>
#include <httpserverrequest.h>
#include <querystring.h>
#include <url.h>

#include <QtCore/QDir>
#include <QtCore/QDebug>
#include <QtCore/QFile>
#include <QtCore/QTimer>
#include <QtCore/QUuid>

#include <memory>

namespace web {
namespace website {

AbstractWebsite::AbstractWebsite(QObject *parent) :
    AbstractWebsite(new AbstractWebsitePrivate, parent)
{
}

AbstractWebsite::~AbstractWebsite()
{
    Q_D(AbstractWebsite);

    qDeleteAll(d->pages);
    delete d_ptr;
}

void AbstractWebsite::publish()
{
    Q_D(AbstractWebsite);

    initPages();

    if ( d->server.isNull() ) {
        d->server.reset(new Tufao::HttpServer);
    }

    if ( !d->server->isListening() ) {
        connect( d->server.data(), &Tufao::HttpServer::requestReady,
                 this, &AbstractWebsite::handleRequest
                 );

        bool isListening = d->server->listen(QHostAddress::Any, d->port);
        if ( !isListening ) qFatal("Couldn't listen on port %i", d->port);
    }

    internationalisation::I18nManager::globalInstance()->loadLanguageTexts("de");
    internationalisation::I18nManager::globalInstance()->loadLanguageTexts("en");
}

void AbstractWebsite::addPage(QString name, page::PageInterface *page)
{
    Q_D(AbstractWebsite);
    d->pages.insert(name, page);
}

void AbstractWebsite::addImageFolder(QString name, QString folder)
{
    Q_D(AbstractWebsite);

    QDir dir(folder);
    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);

    QStringList allFiles = dir.entryList();
    for ( QString file : allFiles ) {
        QString entry = name + QDir::separator() + file;
        QString path = folder + file;
        d->pages.insert(entry.replace(" ", "%20"), new page::resource::ImageResource(path));
    }
}

void AbstractWebsite::addFolderWithImageFolders(const QString & name, const QString & folder)
{
    QDir dir(folder);
    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
    QStringList allFiles = dir.entryList();
    for ( QString dir : allFiles ) {
        QString entry = name + QDir::separator() + dir;
        QString path = folder + dir + QDir::separator();
        addImageFolder(entry.replace(" ", "%20"), path);
    }
}

AbstractWebsite::AbstractWebsite(AbstractWebsitePrivate *pr, QObject *parent) :
    QObject(parent),
    d_ptr(pr)
{
}

void AbstractWebsite::handleRequest(Tufao::HttpServerRequest *request, Tufao::HttpServerResponse *response)
{
    Q_D(AbstractWebsite);

    Url url(request->url());
    QString urlpath = url.path();
    bool isAjaxCall = false;

    if ( urlpath.contains(QStringLiteral("/ajax/")) ) {
        urlpath.replace(QStringLiteral("/ajax/"), "");
        isAjaxCall = true;
    }

    if ( d->pages.contains(urlpath) ) {
        page::PageInterface *pageObj = d->pages.value(urlpath);
        page::SecureContentInterface * secureContent = Q_NULLPTR;
        page::StatefulPageInterface *statefulPage = Q_NULLPTR;
        page::InteractivePageInterface * interactivePage = Q_NULLPTR;
        page::resource::AbstractResource *resource = Q_NULLPTR;


        if ( (interactivePage = dynamic_cast<page::InteractivePageInterface *>(pageObj)) && isAjaxCall ) {
            response->headers().insert(IByteArray("Content-Type"), interactivePage->ajaxMimeType());
            response->writeHead(HttpServerResponse::OK);
            response->end(interactivePage->getAjaxContent());
            return;
        }
        else if ( (statefulPage = dynamic_cast<page::StatefulPageInterface *>(pageObj)) ) {
            statefulPage->setSession(d->session(request, response));
            statefulPage->setRequest(request);
            statefulPage->setResponse(response);
            statefulPage->setRequestPath(url.path());

            if (statefulPage->isFileUploadAllowed() &&
                request->headers().contains(IByteArray("Content-Type"))) {

                QByteArray contentType = request->headers().value(IByteArray("Content-Type"));

                contentType.replace(' ', "");
                QList<QByteArray> splittedContentType = contentType.split(';');

                if(splittedContentType.size() == 2
                   &&
                   splittedContentType.at(0) == "multipart/form-data") {
                    QByteArray boundary = splittedContentType.at(1);

                    auto connData = std::make_shared<QMetaObject::Connection>();
                    *connData = connect(request, &Tufao::HttpServerRequest::data,
                                        [this, request, urlpath](QByteArray data)
                    {
                        handleData(request, urlpath, data);
                    });

                    auto connEnd = std::make_shared<QMetaObject::Connection>();
                    *connEnd  = connect(request, &Tufao::HttpServerRequest::end,
                                        [this, request, statefulPage, boundary, urlpath,
                                        connData, connEnd,
                                        response]
                    {
                        QObject::disconnect(*connData);
                        QObject::disconnect(*connEnd);

                        handleRequestEnd(request, boundary, urlpath);

                        if ( statefulPage->isWaitingForFileUploadToFinish() ) {
                            response->writeHead(HttpServerResponse::OK);
                            response->end(statefulPage->getContent());
                        } else {
                            statefulPage->onFileUploadFinished();
                        }
                    });

                    if (statefulPage->isWaitingForFileUploadToFinish()) {
                        return;
                    }
                }
            }

            // Handle get data
            if ( !url.query().isEmpty() )
                statefulPage->setGetRequestData(QueryString::parse(url.query().toUtf8()));
            else
                statefulPage->clearGetRequestData();

            // Handle post data
            if ( !request->body().isEmpty() )
                statefulPage->setPostRequestData(QueryString::parse(request->body()));
            else
                statefulPage->clearPostRequestData();
        }
        else if ( (resource = dynamic_cast<page::resource::AbstractResource *>(pageObj)) ) {
            resource->setResponse(response);
        }

        if ( (secureContent = dynamic_cast<page::SecureContentInterface *>(pageObj)) ) {
            // The secure content decides if the user can see this content
            if (!secureContent->isUserAllowedToSeeThisContent()) {
                response->writeHead(HttpServerResponse::UNAUTHORIZED);
                response->end(QByteArrayLiteral("Not allowed"));
                return;
            }
        }

        response->writeHead(HttpServerResponse::OK);
        response->end(pageObj->getContent());
    }
    else {
        response->writeHead(HttpServerResponse::NOT_FOUND);
        response->end("Not found");
    }
}

void AbstractWebsite::handleData(HttpServerRequest * request, const QString & path, QByteArray data)
{
    Q_D(AbstractWebsite);
    QByteArray newData = d->getRequestData(request, path);
    newData += data;
    d->setRequestData(request, path, newData);
}

void AbstractWebsite::handleRequestEnd(HttpServerRequest * request, const QByteArray & boundary, const QString & path)
{
    Q_D(AbstractWebsite);

    QByteArray data = d->getRequestData(request, path);

    QString boundaryString = boundary;
    boundaryString.replace("boundary=", "");

    boundaryString = QStringLiteral("--") + boundaryString;
    boundaryString += "\r\n";

    QList<QByteArray> splittedData;
    int startPosition = -1;
    int endPosition = -1;
    const int boundryLength = boundaryString.length();

    QByteArray tempDataForList;

    // Here is the data splitted
    Q_FOREVER {
        startPosition = data.indexOf(boundaryString);

        // if there hasn't been found break out of the loop
        if (startPosition == -1) break;

        endPosition = data.indexOf(boundaryString, startPosition + boundryLength);
        endPosition = (endPosition == -1) ? data.length() : endPosition;

        tempDataForList = data.left(startPosition + endPosition);
        splittedData << tempDataForList;

        // Now we remove this piece of chunk
        data.remove(0, startPosition + endPosition);

        if ( data.isEmpty() ) break;
    }

    QMap<QByteArray, QByteArray> postData;

    const int totalSplittedData = splittedData.size();
    for (int i = 0; i < totalSplittedData; ++i) {
        QByteArray splittedDataChunk = splittedData.at(i);
        // We don't need the boundry
        splittedDataChunk.remove(0, boundryLength);

        // After the boundary comes this
        QString contentDisposition("Content-Disposition: form-data; ");
        if (splittedDataChunk.indexOf(contentDisposition) != 0) continue;

        splittedDataChunk.remove(0, contentDisposition.size());

        // Now comes the name of the form data
        QString nameString("name=\"");
        if (splittedDataChunk.indexOf(nameString) != 0) continue;

        splittedDataChunk.remove(0, nameString.size());

        // Now we want to find the end of the name
        QString nameStringEnd("\"\r\n\r\n");
        int stringEndPos = splittedDataChunk.indexOf(nameStringEnd);

        QString fileNameStringEnd("\"; filename=\"");
        int fileNameStringPos = splittedDataChunk.indexOf(fileNameStringEnd);
        if  (stringEndPos == -1 && fileNameStringPos == -1) continue;

        QByteArray postDataName;
        QByteArray postDataChunk;
        if ( stringEndPos != -1 ) {
            postDataName = splittedDataChunk.left(stringEndPos);
            // Remove post data name
            splittedDataChunk.remove(0, stringEndPos);

            // Remove the chunk between the name and the data
            splittedDataChunk.remove(0, nameStringEnd.size());

            // The data ends with \r\n which we don't want
            postDataChunk = splittedDataChunk.left(splittedDataChunk.size() - 2);
        }
        // This has to be a file
        else {
            postDataName = splittedDataChunk.left(fileNameStringPos);
            // Remove post data name
            splittedDataChunk.remove(0, fileNameStringPos);

            // Remove chunk between filename and post data name
            splittedDataChunk.remove(0, fileNameStringEnd.size());

            // Now we only need to remove the content type
            QString contentType("\"\r\nContent-Type: ");
            int contentTypePos = splittedDataChunk.indexOf(contentType);
            if (contentTypePos == -1) continue;

            QByteArray fileName = splittedDataChunk.left(contentTypePos);

            splittedDataChunk.remove(0, contentTypePos);
            QString contentTypeEndString("\r\n\r\n");
            int contentTypeEndPos = splittedDataChunk.indexOf(contentTypeEndString);
            if (contentTypeEndPos == -1) continue;

            splittedDataChunk.remove(0, contentTypeEndPos);
            splittedDataChunk.remove(0, contentTypeEndString.size());

            // Now we create the file
            QString filePath(QString("temp/uploads/") + QTime::currentTime().toString(QString("hh_mm_ss_zzz/")));
            QDir::current().mkpath(filePath);

            QByteArray uuidForFilename = QUuid::createUuid().toByteArray();
            fileName = uuidForFilename + fileName;
            QFile file(filePath + fileName);

            if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
                const int dataSize = splittedDataChunk.size();
                qint64 currentSize = 0;

                QByteArray writingData;
                const int writingSize = 33000;
                while (currentSize != dataSize) {
                    writingData = splittedDataChunk.left(writingSize);
                    splittedDataChunk.remove(0, writingData.size());
                    currentSize += file.write(writingData);
                    qApp->processEvents();
                }

                postDataChunk = file.fileName().toUtf8();

                file.close();
            } else {
                qWarning() << Q_FUNC_INFO << "File error:" << file.errorString();
            }
        }

        postData.insert(postDataName, postDataChunk);
    }

    page::StatefulPageInterface * page = dynamic_cast<page::StatefulPageInterface *>(d->pages.value(path));
    page->setPostRequestData(postData);
}

}
}
