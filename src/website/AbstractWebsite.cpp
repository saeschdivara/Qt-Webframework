#include "AbstractWebsite.h"
#include "private/AbstractWebsite_p.h"
#include "page/StatefulPageInterface.h"
#include <httpserverresponse.h>
#include <httpserverrequest.h>

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
