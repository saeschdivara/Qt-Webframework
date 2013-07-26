#include "AbstractWebsite.h"
#include "internationalisation/I18nManager.h"
#include "private/AbstractWebsite_p.h"
#include "page/SecureContentInterface.h"
#include "page/StatefulPageInterface.h"
#include "page/resource/AbstractResource.h"
#include "page/resource/ImageResource.h"

#include <headers.h>
#include <httpserverresponse.h>
#include <httpserverrequest.h>
#include <querystring.h>
#include <url.h>

#include <QtCore/QDir>

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

        d->server->listen(QHostAddress::Any, 9999);
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

    if ( d->pages.contains(url.path()) ) {
        page::PageInterface *pageObj = d->pages.value(url.path());
        page::SecureContentInterface * secureContent = Q_NULLPTR;
        page::StatefulPageInterface *statefulPage = Q_NULLPTR;
        page::resource::AbstractResource *resource = Q_NULLPTR;

        if ( (statefulPage = dynamic_cast<page::StatefulPageInterface *>(pageObj)) ) {
            statefulPage->setSession(d->session(request, response));
            statefulPage->setRequest(request);
            statefulPage->setResponse(response);
            statefulPage->setRequestPath(url.path());

            if (statefulPage->isFileUploadAllowed() &&
                request->headers().contains(IByteArray("Content-Type"))) {

                QByteArray contentType = request->headers().value(IByteArray("Content-Type"));

                QMetaObject::Connection dataConnection = connect(request, &Tufao::HttpServerRequest::data,
                                                                 [=](QByteArray data) {
                    qDebug() << request->url();
                    handleData(request, data);
                });

                QMetaObject::Connection endConnection = connect(request, &Tufao::HttpServerRequest::end, [=] {
                    disconnect(dataConnection);
                    disconnect(endConnection);
                    handleRequestEnd(request);
                });

                QList<QByteArray> da = contentType.split(';');
                qDebug() << da;

                if (statefulPage->isWaitingForFileUploadToFinish()) {
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

    qDebug() << "end of mine";
}

void AbstractWebsite::handleData(HttpServerRequest * request, QByteArray data)
{
    Q_UNUSED(request);
    qDebug() << "data : " << data.size();
}

void AbstractWebsite::handleRequestEnd(HttpServerRequest * request)
{
    Q_UNUSED(request);
}

}
}
