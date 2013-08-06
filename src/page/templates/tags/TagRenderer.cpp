#include "TagRenderer.h"

namespace web
{
namespace page
{
namespace templates
{
namespace tags
{

class TagRendererPrivate
{
    public:
        QByteArray content;
};

TagRenderer::TagRenderer() :
    d_ptr(new TagRendererPrivate)
{
}

TagRenderer::~TagRenderer()
{
    delete d_ptr;
}

void TagRenderer::setContent(const QByteArray & content)
{
    Q_D(TagRenderer);
    d->content = content;
}

}
}
}
}
