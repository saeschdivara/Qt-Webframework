#ifndef VIDEOELEMENT_H
#define VIDEOELEMENT_H

#include "webframework-qt_global.h"
#include "AbstractHtmlElement.h"

namespace web {
namespace htmlelement {

class VideoElementPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT VideoElement : public AbstractHtmlElement
{
    public:
        VideoElement();

    private:
        Q_DECLARE_PRIVATE(VideoElement)
};

}
}

#endif // VIDEOELEMENT_H
