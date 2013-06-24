#ifndef ABSTRACTRESOURCE_P_H
#define ABSTRACTRESOURCE_P_H

#include <httpserverresponse.h>

namespace web
{
namespace page
{
namespace resource
{

class AbstractResourcePrivate
{
    public:
        QString fileName;
        Tufao::HttpServerResponse *response;
};

}
}
}

#endif // ABSTRACTRESOURCE_P_H
