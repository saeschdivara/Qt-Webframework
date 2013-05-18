#include "HtmlElement.h"
#include "private/AbstractHtmlElement_p.h"

namespace web {
namespace htmlelement {

class HtmlElementPrivate : public AbstractHtmlElementPrivate
{
    public:
};

HtmlElement::HtmlElement() :
    AbstractHtmlElement(new HtmlElementPrivate)
{
    Q_D(HtmlElement);
    d->tag = QByteArray("html");
}

}
}
