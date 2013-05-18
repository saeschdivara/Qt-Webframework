#ifndef INPUTELEMENT_H
#define INPUTELEMENT_H

#include "webframework-qt_global.h"
#include "AbstractHtmlElement.h"

namespace web {
namespace htmlelement {

class InputElementPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT InputElement : public AbstractHtmlElement
{
    public:
        InputElement();

    private:
        Q_DECLARE_PRIVATE(InputElement)
};

}
}

#endif // INPUTELEMENT_H
