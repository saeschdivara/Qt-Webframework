#include "AbstractRenderedPage.h"
#include "private/AbstractRenderedPage_p.h"

namespace web {
namespace page {

QByteArray AbstractRenderedPage::getContent()
{
    Q_D(AbstractRenderedPage);

    render();
    return d->data;
}

void AbstractRenderedPage::setSession(Tufao::SessionStore *s)
{
    Q_D(AbstractRenderedPage);
    d->session = s;
}

void AbstractRenderedPage::setRequest(Tufao::HttpServerRequest *r)
{
    Q_D(AbstractRenderedPage);
    d->request = r;
}

void AbstractRenderedPage::setResponse(Tufao::HttpServerResponse *r)
{
    Q_D(AbstractRenderedPage);
    d->response = r;
}

AbstractRenderedPage::AbstractRenderedPage(AbstractRenderedPagePrivate *d) :
    d_ptr(d)
{
}

}

}
