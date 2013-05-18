#ifndef ABSTRACTRENDEREDPAGE_H
#define ABSTRACTRENDEREDPAGE_H

#include "webframework-qt_global.h"
#include "StatefulPageInterface.h"
#include "htmlelement/AbstractHtmlElement.h"
#include "htmlelement/HtmlElement.h"

namespace web
{
namespace page
{

class AbstractRenderedPagePrivate;

class WEBFRAMEWORKQTSHARED_EXPORT AbstractRenderedPage : public  StatefulPageInterface
{
    public:
        virtual ~AbstractRenderedPage();

        virtual QByteArray getContent() Q_DECL_OVERRIDE;
        virtual void setSession(Tufao::SessionStore *s) Q_DECL_OVERRIDE;
        virtual void setRequest(Tufao::HttpServerRequest *r) Q_DECL_OVERRIDE;
        virtual void setResponse(Tufao::HttpServerResponse *r) Q_DECL_OVERRIDE;

    protected:
        AbstractRenderedPagePrivate *d_ptr;
        AbstractRenderedPage(AbstractRenderedPagePrivate *d);

        htmlelement::AbstractHtmlElement* rootElement();
        inline htmlelement::HtmlElement* htmlElement() {
            return dynamic_cast<htmlelement::HtmlElement *>(rootElement());
        }

        virtual void render() = 0;

    private:
        Q_DECLARE_PRIVATE(AbstractRenderedPage)
};

}
}

#endif // ABSTRACTRENDEREDPAGE_H
