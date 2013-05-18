#ifndef HTMLELEMENT_H
#define HTMLELEMENT_H

#include "webframework-qt_global.h"
#include "AbstractHtmlElement.h"

namespace web {
namespace htmlelement {

class HtmlElementPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT HtmlElement : public AbstractHtmlElement
{
    public:
        HtmlElement();

    private:
        Q_DECLARE_PRIVATE(HtmlElement)
};

}
}

#endif // HTMLELEMENT_H
