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

    if ( !d->isVisible ) {
            return QByteArray();
        }

    QByteArray html = "<" + tag();

    QHashIterator<QByteArray, QByteArray> attIt(d->attributes);
    while (attIt.hasNext()) {
            attIt.next();
            QByteArray attrKey = attIt.key();
            QByteArray attrValue = attIt.value();

            if ( attrValue.isEmpty() ) {
                    html += " " + attrKey;
                }
            else {
                    html += " " + attrKey + "=\"" + attrValue + "\"";
                }
        }

    html += ">";

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

QList<AbstractHtmlElement *> &AbstractHtmlElement::children()
{
    Q_D(AbstractHtmlElement);
    return d->children;
}

AbstractHtmlElement *AbstractHtmlElement::append(AbstractHtmlElement *ele)
{
    Q_D(AbstractHtmlElement);
    d->children.append(ele);
    return ele;
}

AbstractHtmlElement *AbstractHtmlElement::addAttribute(QByteArray key, QByteArray value)
{
    Q_D(AbstractHtmlElement);
    d->attributes.insert(key, value);
    return this;
}

QByteArray AbstractHtmlElement::attribute(QByteArray key)
{
    Q_D(AbstractHtmlElement);
    return d->attributes.value(key);
}

AbstractHtmlElement::AbstractHtmlElement(AbstractHtmlElementPrivate *d) :
    d_ptr(d)
{
}

}
}
