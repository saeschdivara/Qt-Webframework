#ifndef ABSTRACTWEBSITE_H
#define ABSTRACTWEBSITE_H

#include "webframework-qt_global.h"

namespace web
{
namespace website
{

class AbstractWebsitePrivate;

class WEBFRAMEWORKQTSHARED_EXPORT AbstractWebsite : public QObject
{
        Q_OBJECT
    public:
        explicit AbstractWebsite(QObject *parent = 0);

    protected:
        AbstractWebsite(AbstractWebsitePrivate *pr, QObject *parent = 0);
        AbstractWebsitePrivate *d_ptr;

    private:
        Q_DECLARE_PRIVATE(AbstractWebsite)
};

}
}

#endif // ABSTRACTWEBSITE_H
