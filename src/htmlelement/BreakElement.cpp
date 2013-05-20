#include "BreakElement.h"
#include "private/AbstractHtmlElement_p.h"

namespace web {
namespace htmlelement {

class BreakElementPrivate : public AbstractHtmlElementPrivate
{
    public:
};

BreakElement::BreakElement() :
    AbstractHtmlElement(new BreakElementPrivate)
{
    Q_D(BreakElement);
    d->tag = QByteArray("br");
}

}
}
