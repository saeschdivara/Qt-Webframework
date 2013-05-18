#include "HeadElement.h"
#include "private/AbstractHtmlElement_p.h"

namespace web {
namespace htmlelement {

class HeadElementPrivate : public AbstractHtmlElementPrivate
{
    public:
};

HeadElement::HeadElement() :
    AbstractHtmlElement(new HeadElementPrivate)
{
    Q_D(HeadElement);
    d->tag = QByteArray("head");
}

}
}
