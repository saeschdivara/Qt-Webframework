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

void AbstractRenderedPage::setSession(website::WebSession *s)
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

void AbstractRenderedPage::setPostRequestData(QMap<QByteArray, QByteArray> data)
{
    Q_D(AbstractRenderedPage);
    d->post = data;
}

void AbstractRenderedPage::clearPostRequestData()
{
    Q_D(AbstractRenderedPage);
    d->post.clear();
}

void AbstractRenderedPage::setGetRequestData(QMap<QByteArray, QByteArray> data)
{
    Q_D(AbstractRenderedPage);
    d->get = data;
}

void AbstractRenderedPage::clearGetRequestData()
{
    Q_D(AbstractRenderedPage);
    d->get.clear();
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
