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

DivElement *DivElement::setHeight(quint32 h)
{
    addAttribute("height", QByteArray::number(h));
    return this;
}

DivElement *DivElement::setWidth(quint32 h)
{
    addAttribute("width", QByteArray::number(h));
    return this;
}

TextElement *DivElement::appendText(QByteArray text)
{
    TextElement* t = new TextElement(text);
    append(t);
    return t;
}

}
}
