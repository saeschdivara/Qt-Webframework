#include "VideoElement.h"
#include "private/AbstractHtmlElement_p.h"

namespace web {
namespace htmlelement {

class VideoElementPrivate : public AbstractHtmlElementPrivate
{
    public:
};

VideoElement::VideoElement() :
    AbstractHtmlElement(new VideoElementPrivate)
{
    Q_D(VideoElement);
    d->tag = QByteArray("video");
}

}
}
