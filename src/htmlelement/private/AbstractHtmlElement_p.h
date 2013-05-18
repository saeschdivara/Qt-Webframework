#ifndef ABSTRACTHTMLELEMENT_P_H
#define ABSTRACTHTMLELEMENT_P_H

#include "../AbstractHtmlElement.h"
#include <QtCore/QList>

namespace web {
namespace htmlelement {

class AbstractHtmlElementPrivate
{
    public:
        AbstractHtmlElement *parent;
        QList<AbstractHtmlElement *> children;

        bool isVisible;
        bool isReadonly;
};

}
}

#endif // ABSTRACTHTMLELEMENT_P_H
