#include "AbstractWebsite.h"
#include "internationalisation/I18nManager.h"
#include "private/AbstractWebsite_p.h"
#include "page/StatefulPageInterface.h"
#include <headers.h>
#include <httpserverresponse.h>
#include <httpserverrequest.h>

namespace web {
namespace website {

QHash<QByteArray, QByteArray> parseUserData(QByteArray data) {
    QHash<QByteArray, QByteArray> parsedData;
    QList<QByteArray> pairedData = data.split('&');

    QListIterator<QByteArray> it(pairedData);
    while ( it.hasNext() ) {
            QByteArray pair = it.next();
            QList<QByteArray> userDataPairs = pair.split('=');

            if (userDataPairs.size() == 1) {
                    parsedData.insert(userDataPairs.at(0), "");
                }
            else if (userDataPairs.size() == 2){
                    parsedData.insert(userDataPairs.at(0), userDataPairs.at(1));
                }
        }

    return parsedData;
}

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

    internationalisation::I18nManager::globalInstance()->loadLanguageTexts("en");
}

void AbstractWebsite::addPage(QString name, page::PageInterface *page)
{
    Q_D(AbstractWebsite);
    d->pages.insert(name, page);
}

AbstractWebsite::AbstractWebsite(AbstractWebsitePrivate *pr, QObject *parent) :
    QObject(parent),
    d_ptr(pr)
{
}

void AbstractWebsite::handleRequest(Tufao::HttpServerRequest &request, Tufao::HttpServerResponse &response)
{
    Q_D(AbstractWebsite);

    QString url = request.url().toDisplayString();

    if ( d->pages.contains(url) ) {
            page::PageInterface *pageObj = d->pages.value(url);
            page::StatefulPageInterface *statefulPage = Q_NULLPTR;

            if ( (statefulPage = dynamic_cast<page::StatefulPageInterface *>(pageObj)) ) {
                    statefulPage->setSession(&d->sessionStore);
                    statefulPage->setRequest(&request);
                    statefulPage->setResponse(&response);

                    statefulPage->setGetRequestData(parseUserData(request.url().query().toUtf8()));
                    statefulPage->setPostRequestData(parseUserData(request.readBody()));
                }

            response.writeHead(Tufao::HttpServerResponse::OK);
            response.end(pageObj->getContent());
        }
    else {
            response.writeHead(Tufao::HttpServerResponse::NOT_FOUND);
            response.end("Not found");
        }
}

}
}
