#ifndef DARTRESOURCE_H
#define DARTRESOURCE_H

#include "AbstractResource.h"

namespace web
{
namespace page
{
namespace resource
{

class DartResourcePrivate;

class WEBFRAMEWORKQTSHARED_EXPORT DartResource : public AbstractResource
{
    public:
        DartResource(const QString &dartFile, const QString &jsFile);

    protected:
        void compileDartFile();

    private:
        Q_DECLARE_PRIVATE(DartResource)
};

}
}
}

#endif // DARTRESOURCE_H
