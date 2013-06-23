#include "AbstractResource.h"

namespace web
{
namespace page
{
namespace model
{

AbstractResource::AbstractResource()
{
}

QByteArray AbstractResource::getContent()
{
    return QByteArrayLiteral("");
}

}
}
}
