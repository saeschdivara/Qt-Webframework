#include "AbstractResource.h"

namespace web
{
namespace page
{
namespace resource
{

AbstractResource::~AbstractResource()
{
}

QByteArray AbstractResource::getContent()
{
    return QByteArrayLiteral("");
}

AbstractResource::AbstractResource(AbstractResourcePrivate *d) :
    d_ptr(d)
{
}

}
}
}
