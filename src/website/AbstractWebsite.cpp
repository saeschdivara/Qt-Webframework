#include "AbstractWebsite.h"

using namespace web::website;

namespace web {
namespace website {

class AbstractWebsitePrivate
{
public:
        QUrl url;
};

AbstractWebsite::AbstractWebsite(QObject *parent) :
    QObject(parent),
    d_ptr(new AbstractWebsitePrivate)
{
}

AbstractWebsite::AbstractWebsite(AbstractWebsitePrivate *pr, QObject *parent) :
    QObject(parent),
    d_ptr(pr)
{
}

}
}
