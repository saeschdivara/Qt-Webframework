#ifndef DIVELEMENT_H
#define DIVELEMENT_H

#include "webframework-qt_global.h"
#include "AbstractHtmlElement.h"

namespace web {
namespace htmlelement {

class DivElementPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT DivElement : public AbstractHtmlElement
{
    public:
        DivElement();

        DivElement* setHeight(quint32 h);
        DivElement* setWidth(quint32 h);

    private:
        Q_DECLARE_PRIVATE(DivElement)
};

}
}

#endif // DIVELEMENT_H
