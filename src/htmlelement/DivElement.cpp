#include "DivElement.h"
#include "private/AbstractHtmlElement_p.h"

namespace web {
namespace htmlelement {

class DivElementPrivate : public AbstractHtmlElementPrivate
{
    public:
};

DivElement::DivElement() :
    AbstractHtmlElement(new DivElementPrivate)
{
    Q_D(DivElement);
    d->tag = QByteArray("div");
}

}
}
