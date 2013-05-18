#ifndef HTMLELEMENT_H
#define HTMLELEMENT_H

#include "webframework-qt_global.h"
#include "AbstractHtmlElement.h"
#include "BodyElement.h"
#include "HeadElement.h"

namespace web {
namespace htmlelement {

class HtmlElementPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT HtmlElement : public AbstractHtmlElement
{
    public:
        HtmlElement();

        void appendHeader(HeadElement *ele);
        HeadElement* head();

        void appendBody(BodyElement *ele);
        BodyElement* body();

    private:
        Q_DECLARE_PRIVATE(HtmlElement)
};

}
}

#endif // HTMLELEMENT_H
