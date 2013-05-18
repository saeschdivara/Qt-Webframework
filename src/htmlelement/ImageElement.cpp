#include "ImageElement.h"
#include "private/AbstractHtmlElement_p.h"

namespace web {
namespace htmlelement {

class ImageElementPrivate : public AbstractHtmlElementPrivate
{
    public:
};

ImageElement::ImageElement() :
    AbstractHtmlElement(new ImageElementPrivate)
{
    Q_D(ImageElement);
    d->tag = QByteArray("img");
}

}
}
