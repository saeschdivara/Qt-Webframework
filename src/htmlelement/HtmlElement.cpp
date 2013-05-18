#include "HtmlElement.h"
#include "private/AbstractHtmlElement_p.h"

namespace web {
namespace htmlelement {

class HtmlElementPrivate : public AbstractHtmlElementPrivate
{
    public:
        BodyElement *body;
        HeadElement *head;
};

HtmlElement::HtmlElement() :
    AbstractHtmlElement(new HtmlElementPrivate)
{
    Q_D(HtmlElement);
    d->tag = QByteArray("html");
}

void HtmlElement::appendHeader(HeadElement *ele)
{
    Q_D(HtmlElement);
    d->head = ele;
    append(ele);
}

HeadElement *HtmlElement::head()
{
    Q_D(HtmlElement);
    return d->head;
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
