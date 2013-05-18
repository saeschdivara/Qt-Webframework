#ifndef BODYELEMENT_H
#define BODYELEMENT_H

#include "webframework-qt_global.h"
#include "AbstractHtmlElement.h"

namespace web {
namespace htmlelement {

class BodyElementPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT BodyElement : public AbstractHtmlElement
{
    public:
        BodyElement();

    private:
        Q_DECLARE_PRIVATE(BodyElement)
};

}
}

#endif // BODYELEMENT_H
