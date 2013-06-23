#ifndef ABSTRACTRESOURCE_H
#define ABSTRACTRESOURCE_H

#include "webframework-qt_global.h"
#include "page/PageInterface.h"

namespace web
{
namespace page
{
namespace model
{

class WEBFRAMEWORKQTSHARED_EXPORT AbstractResource : public PageInterface
{
    public:
        AbstractResource();
        virtual ~AbstractResource();

        virtual QByteArray getContent() Q_DECL_OVERRIDE;
};

}
}
}

#endif // ABSTRACTRESOURCE_H
