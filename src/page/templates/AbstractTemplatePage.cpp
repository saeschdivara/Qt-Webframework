#include "AbstractTemplatePage.h"
#include "private/AbstractTemplatePage_p.h"

namespace web
{
namespace page
{
namespace templates
{

AbstractTemplatePage::~AbstractTemplatePage()
{
}

QByteArray AbstractTemplatePage::getContent()
{
    return QByteArray();
}

void AbstractTemplatePage::setSession(Tufao::SessionStore *s)
{
    Q_D(AbstractTemplatePage);
    d->session = s;
}

void AbstractTemplatePage::setRequest(Tufao::HttpServerRequest *r)
{
    Q_D(AbstractTemplatePage);
    d->request = r;
}

void AbstractTemplatePage::setResponse(Tufao::HttpServerResponse *r)
{
    Q_D(AbstractTemplatePage);
    d->response = r;
}

void AbstractTemplatePage::setPostRequestData(QHash<QByteArray, QByteArray> data)
{
    Q_D(AbstractTemplatePage);
    d->post = data;
}

void AbstractTemplatePage::setGetRequestData(QHash<QByteArray, QByteArray> data)
{
    Q_D(AbstractTemplatePage);
    d->get = data;
}

AbstractTemplatePage::AbstractTemplatePage(AbstractTemplatePagePrivate *d) :
    d_ptr(d)
{
}

}
}
}
