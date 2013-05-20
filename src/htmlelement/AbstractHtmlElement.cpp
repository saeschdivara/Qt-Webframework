#include "AbstractHtmlElement.h"
#include "private/AbstractHtmlElement_p.h"
#include <QtCore/QDebug>

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

QList<AbstractHtmlElement *> AbstractHtmlElement::findAllElementsByTag(QByteArray tag)
{
    QList<AbstractHtmlElement *> eles;
    const int total = children().size();

    for (int i = 0; i < total; ++i) {
            AbstractHtmlElement *childEle = children().at(i);
            if (childEle->tag() == tag) {
                    eles.append(childEle);
                }
        }

    return eles;
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

    if ( d->style ) {
            html += " style=\"" + d->style->data() + "\"";
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

AbstractHtmlElement *AbstractHtmlElement::setID(QByteArray id)
{
    Q_D(AbstractHtmlElement);
    d->attributes.insert("id", id);
    d->attributes.insert("name", id);
    return this;
}

QByteArray AbstractHtmlElement::ID()
{
    Q_D(AbstractHtmlElement);
    return d->attributes["id"];
}

QByteArray AbstractHtmlElement::attribute(QByteArray key)
{
    Q_D(AbstractHtmlElement);
    return d->attributes.value(key);
}

AbstractHtmlElement *AbstractHtmlElement::findElementByID(QByteArray id)
{
    AbstractHtmlElement *ele = Q_NULLPTR;
    const int total = children().size();

    for (int i = 0; i < total; ++i) {
            AbstractHtmlElement *childEle = children().at(i);
            if (childEle->ID() == id) {
                    ele = childEle;
                    break;
                }
        }

    return ele;
}

css::ElementCss *AbstractHtmlElement::style()
{
    Q_D(AbstractHtmlElement);
    return d->style;
}

css::ElementCss *AbstractHtmlElement::createStyle()
{
    Q_D(AbstractHtmlElement);
    if ( !d->style ) {
            d->style = new css::ElementCss;
        }

    return d->style;
}

AbstractHtmlElement::AbstractHtmlElement(AbstractHtmlElementPrivate *d) :
    d_ptr(d)
{
}

}
}
