#ifndef IMAGEELEMENT_H
#define IMAGEELEMENT_H

#include "webframework-qt_global.h"
#include "AbstractHtmlElement.h"

namespace web {
namespace htmlelement {

class ImageElementPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT ImageElement : public AbstractHtmlElement
{
    public:
        ImageElement();
        ImageElement(QByteArray src);

    private:
        Q_DECLARE_PRIVATE(ImageElement)
};

}
}

#endif // IMAGEELEMENT_H
