#include "ElementCss.h"
#include <QtCore/QHash>

namespace web
{
namespace css
{

class ElementCssPrivate
{
    public:
        QHash<QByteArray, QByteArray> attributes;
};

ElementCss::ElementCss() :
    ElementCss(new ElementCssPrivate)
{
}

QByteArray ElementCss::data()
{
    Q_D(ElementCss);
    QByteArray data;

    QHashIterator<QByteArray, QByteArray> it(d->attributes);
    while ( it.hasNext() ) {
            it.next();

            QByteArray key = it.key();
            QByteArray value = it.value();

            data += key + ":" + value + ";";
        }

    return data;
}

ElementCss *ElementCss::setAttribute(QByteArray key, QByteArray value)
{
    Q_D(ElementCss);
    d->attributes[key] = value;
    return this;
}

ElementCss::ElementCss(ElementCssPrivate *d) :
    d_ptr(d)
{
}

}
}
