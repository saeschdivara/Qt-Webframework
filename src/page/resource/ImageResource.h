#ifndef IMAGERESOURCE_H
#define IMAGERESOURCE_H

#include "AbstractResource.h"

namespace web
{
namespace page
{
namespace resource
{

class ImageResourcePrivate;

class WEBFRAMEWORKQTSHARED_EXPORT ImageResource : public AbstractResource
{
    public:
        ImageResource(QString fileName);

    private:
        Q_DECLARE_PRIVATE(ImageResource)
};

}
}
}

#endif // IMAGERESOURCE_H
