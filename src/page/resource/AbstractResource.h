#ifndef ABSTRACTRESOURCE_H
#define ABSTRACTRESOURCE_H

#include "webframework-qt_global.h"
#include "page/PageInterface.h"

namespace web
{
namespace page
{
namespace resource
{

class AbstractResourcePrivate;

class WEBFRAMEWORKQTSHARED_EXPORT AbstractResource : public PageInterface
{
    public:
        virtual ~AbstractResource();

        virtual QByteArray getContent() Q_DECL_OVERRIDE;

    protected:
        AbstractResourcePrivate *d_ptr;
        AbstractResource(AbstractResourcePrivate *d);

    private:
        Q_DECLARE_PRIVATE(AbstractResource)
};

}
}
}

#endif // ABSTRACTRESOURCE_H
