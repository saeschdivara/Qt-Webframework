#ifndef BREAKELEMENT_H
#define BREAKELEMENT_H

#include "webframework-qt_global.h"
#include "AbstractHtmlElement.h"

namespace web {
namespace htmlelement {

class BreakElementPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT BreakElement : public AbstractHtmlElement
{
    public:
        BreakElement();

    private:
        Q_DECLARE_PRIVATE(BreakElement)
};

}
}

#endif // BREAKELEMENT_H
