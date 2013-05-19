#include "TextElement.h"
#include "private/AbstractHtmlElement_p.h"

namespace web {
namespace htmlelement {

class TextElementPrivate : public AbstractHtmlElementPrivate
{
    public:
        QByteArray text;
};

TextElement::TextElement(QByteArray text) :
    AbstractHtmlElement(new TextElementPrivate)
{
    Q_D(TextElement);
    d->text = text;
}

QByteArray TextElement::toHtml()
{
    Q_D(TextElement);
    return d->text;
}

}
}
