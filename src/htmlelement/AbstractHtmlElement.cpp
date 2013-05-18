#include "AbstractHtmlElement.h"
#include "private/AbstractHtmlElement_p.h"

namespace web {
namespace htmlelement {

AbstractHtmlElement::~AbstractHtmlElement()
{
    Q_D(AbstractHtmlElement);
    qDeleteAll(d->children);
}

QByteArray AbstractHtmlElement::toHtml()
{
    return QByteArray();
}

QByteArray AbstractHtmlElement::toJson()
{
    return QByteArray();
}

void AbstractHtmlElement::setVisible(bool b)
{
    Q_D(AbstractHtmlElement);
    d->isVisible = b;
}

bool AbstractHtmlElement::isVisible()
{
    Q_D(AbstractHtmlElement);
    return d->isVisible;
}

void AbstractHtmlElement::setReadonly(bool b)
{
    Q_D(AbstractHtmlElement);
    d->isReadonly = b;
}

bool AbstractHtmlElement::isReadonly()
{
    Q_D(AbstractHtmlElement);
    return d->isReadonly;
}

void AbstractHtmlElement::setParent(AbstractHtmlElement *ele)
{
    Q_D(AbstractHtmlElement);
    d->parent = ele;
}

AbstractHtmlElement::AbstractHtmlElement(AbstractHtmlElementPrivate *d) :
    d_ptr(d)
{
}

}
}

