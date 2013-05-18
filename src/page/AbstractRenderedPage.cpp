#include "AbstractRenderedPage.h"
#include "private/AbstractRenderedPage_p.h"

namespace web {
namespace page {

AbstractRenderedPage::~AbstractRenderedPage()
{
    Q_D(AbstractRenderedPage);
    delete d->root;
}

QByteArray AbstractRenderedPage::getContent()
{
    Q_D(AbstractRenderedPage);

    render();

    if ( d->root ) {
            return d->root->toHtml();
        }
    else {
            return d->data;
        }
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

htmlelement::AbstractHtmlElement *AbstractRenderedPage::rootElement()
{
    Q_D(AbstractRenderedPage);
    return d->root;
}

AbstractRenderedPage::AbstractRenderedPage(AbstractRenderedPagePrivate *d) :
    d_ptr(d)
{
}

}

}
