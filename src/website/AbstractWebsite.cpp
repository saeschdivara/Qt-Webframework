#include "AbstractWebsite.h"
#include "private/AbstractWebsite_p.h"

namespace web {
namespace website {

AbstractWebsite::AbstractWebsite(QObject *parent) :
    AbstractWebsite(new AbstractWebsitePrivate, parent)
{
}

void AbstractWebsite::publish()
{
    Q_D(AbstractWebsite);

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

void AbstractWebsite::addPage(page::PageInterface *page)
{
    Q_D(AbstractWebsite);
    d->pages.append(page);
}

AbstractWebsite::AbstractWebsite(AbstractWebsitePrivate *pr, QObject *parent) :
    QObject(parent),
    d_ptr(pr)
{
}

}
}
