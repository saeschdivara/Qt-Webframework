#ifndef BODYELEMENT_H
#define BODYELEMENT_H

#include "webframework-qt_global.h"
#include "AbstractHtmlElement.h"
#include "DivElement.h"
#include "ImageElement.h"
#include "VideoElement.h"

namespace web {
namespace htmlelement {

class BodyElementPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT BodyElement : public AbstractHtmlElement
{
    public:
        BodyElement();

        DivElement* appendDiv(DivElement *div = new DivElement);
        VideoElement* appendVideo(VideoElement *v = new VideoElement);

    private:
        Q_DECLARE_PRIVATE(BodyElement)
};

}
}

#endif // BODYELEMENT_H
