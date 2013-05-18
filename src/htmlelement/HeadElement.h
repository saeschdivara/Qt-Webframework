#ifndef HEADELEMENT_H
#define HEADELEMENT_H

#include "webframework-qt_global.h"
#include "AbstractHtmlElement.h"

namespace web {
namespace htmlelement {

class HeadElementPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT HeadElement : public AbstractHtmlElement
{
    public:
        HeadElement();

    private:
        Q_DECLARE_PRIVATE(HeadElement)
};

}
}

#endif // HEADELEMENT_H
