#include "BodyElement.h"
#include "private/AbstractHtmlElement_p.h"

namespace web {
namespace htmlelement {

class BodyElementPrivate : public AbstractHtmlElementPrivate
{
    public:
};

BodyElement::BodyElement() :
    AbstractHtmlElement(new BodyElementPrivate)
{
    Q_D(BodyElement);
    d->tag = QByteArray("body");
}

DivElement *BodyElement::appendDiv(DivElement *div)
{
    append(div);
    return div;
}

VideoElement *BodyElement::appendVideo(VideoElement *v)
{
    append(v);
    return v;
}

}
}
