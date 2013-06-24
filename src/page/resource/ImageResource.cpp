#include "ImageResource.h"
#include "private/AbstractResource_p.h"

namespace web
{
namespace page
{
namespace resource
{

class ImageResourcePrivate : public AbstractResourcePrivate
{
    public:
};

ImageResource::ImageResource(QString fileName) :
    AbstractResource(new ImageResourcePrivate)
{
    Q_D(ImageResource);
    d->fileName = fileName;
}

}
}
}
