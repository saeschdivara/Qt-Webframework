#include "AbstractWebsite.h"
#include "private/AbstractWebsite_p.h"

namespace web {
namespace website {

AbstractWebsite::AbstractWebsite(QObject *parent) :
    AbstractWebsite(new AbstractWebsitePrivate, parent)
{
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
