#include "AbstractHtmlElement.h"
#include "private/AbstractHtmlElement_p.h"

namespace web {
namespace htmlelement {

AbstractHtmlElement::~AbstractHtmlElement()
{
    Q_D(AbstractHtmlElement);
    qDeleteAll(d->children);
}

QByteArray AbstractHtmlElement::tag() const
{
    Q_D(const AbstractHtmlElement);
    return d->tag;
}

QByteArray AbstractHtmlElement::toHtml()
{
    Q_D(AbstractHtmlElement);
    QByteArray html = "<" + tag() + ">";

    QListIterator<AbstractHtmlElement *> it(d->children);
    while( it.hasNext() ) {
            AbstractHtmlElement *ele = it.next();
            html += ele->toHtml();
        }

    html += "</" + tag() + ">";

    return html;
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

QList<AbstractHtmlElement *> AbstractHtmlElement::children()
{
    Q_D(AbstractHtmlElement);
    return d->children;
}

void AbstractHtmlElement::append(AbstractHtmlElement *ele)
{
    Q_D(AbstractHtmlElement);
    d->children.append(ele);
}

AbstractHtmlElement::AbstractHtmlElement(AbstractHtmlElementPrivate *d) :
    d_ptr(d)
{
}

}
}
