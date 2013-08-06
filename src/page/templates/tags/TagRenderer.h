#ifndef TAGRENDERER_H
#define TAGRENDERER_H

#include "TagInterface.h"

namespace web
{
namespace page
{
namespace templates
{
namespace tags
{

class TagRendererPrivate;

/**
 * @brief The TagRenderer class
 *
 * @author Sascha Häusler <saeschdivara@gmail.com>
 * @since 0.3
 */
class WEBFRAMEWORKQTSHARED_EXPORT TagRenderer
{
    public:
        TagRenderer();
        ~TagRenderer();

        void setContent(const QByteArray & content);
        QByteArray render();

    protected:
        TagRendererPrivate * d_ptr;

    private:
        Q_DECLARE_PRIVATE(TagRenderer)
};

}
}
}
}

#endif // TAGRENDERER_H
