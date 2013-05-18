#include "InputElement.h"
#include "private/AbstractHtmlElement_p.h"

namespace web {
namespace htmlelement {

class InputElementPrivate : public AbstractHtmlElementPrivate
{
    public:
};

InputElement::InputElement() :
    AbstractHtmlElement(new InputElementPrivate)
{
    Q_D(InputElement);
    d->tag = QByteArray("input");
}

}
}
