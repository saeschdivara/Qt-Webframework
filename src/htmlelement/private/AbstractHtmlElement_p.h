#ifndef ABSTRACTHTMLELEMENT_P_H
#define ABSTRACTHTMLELEMENT_P_H

#include "../AbstractHtmlElement.h"
#include <QtCore/QByteArray>
#include <QtCore/QHash>
#include <QtCore/QList>

namespace web {
namespace htmlelement {

class AbstractHtmlElementPrivate
{
    public:
        AbstractHtmlElement *parent;
        QList<AbstractHtmlElement *> children;

        QByteArray tag;
        QHash<QByteArray, QByteArray> attributes;

        bool isVisible;
        bool isReadonly;
};

}
}

#endif // ABSTRACTHTMLELEMENT_P_H
