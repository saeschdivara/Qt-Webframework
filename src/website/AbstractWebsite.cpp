#include "AbstractWebsite.h"
#include "internationalisation/I18nManager.h"
#include "private/AbstractWebsite_p.h"
#include "page/StatefulPageInterface.h"
#include "page/resource/AbstractResource.h"
#include "page/resource/ImageResource.h"

#include <headers.h>
#include <httpserverresponse.h>
#include <httpserverrequest.h>
#include <querystring.h>
#include <url.h>

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

void AbstractWebsite::handleRequest(Tufao::HttpServerRequest *request, Tufao::HttpServerResponse *response)
{
    Q_D(AbstractWebsite);

    Url url(request->url());

    if ( d->pages.contains(url.path()) ) {
            page::PageInterface *pageObj = d->pages.value(url.path());
            page::StatefulPageInterface *statefulPage = Q_NULLPTR;
            page::resource::AbstractResource *resource = Q_NULLPTR;

            if ( (statefulPage = dynamic_cast<page::StatefulPageInterface *>(pageObj)) ) {
                    statefulPage->setSession(d->session(request, response));
                    statefulPage->setRequest(request);
                    statefulPage->setResponse(response);

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

            response->writeHead(HttpServerResponse::OK);
            response->end(pageObj->getContent());
        }
    else {
            response->writeHead(HttpServerResponse::NOT_FOUND);
            response->end("Not found");
        }
}

}
}
