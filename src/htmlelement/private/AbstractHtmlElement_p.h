#ifndef ABSTRACTHTMLELEMENT_P_H
#define ABSTRACTHTMLELEMENT_P_H

#include "../AbstractHtmlElement.h"
#include <QtCore/QByteArray>
#include <QtCore/QList>

namespace web {
namespace htmlelement {

class AbstractHtmlElementPrivate
{
    public:
        AbstractHtmlElement *parent;
        QList<AbstractHtmlElement *> children;

        const QByteArray tag;

        bool isVisible;
        bool isReadonly;
};

}
}

#endif // ABSTRACTHTMLELEMENT_P_H
