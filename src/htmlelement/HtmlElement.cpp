#include "HtmlElement.h"
#include "private/AbstractHtmlElement_p.h"

namespace web {
namespace htmlelement {

class HtmlElementPrivate : public AbstractHtmlElementPrivate
{
    public:
        BodyElement *body;
};

HtmlElement::HtmlElement() :
    AbstractHtmlElement(new HtmlElementPrivate)
{
    Q_D(HtmlElement);
    d->tag = QByteArray("html");
}

void HtmlElement::appendBody(BodyElement *ele)
{
    Q_D(HtmlElement);
    d->body = ele;
    append(ele);
}

BodyElement *HtmlElement::body()
{
    Q_D(HtmlElement);
    return d->body;
}

}
}
