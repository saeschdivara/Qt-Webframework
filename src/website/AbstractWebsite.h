#ifndef ABSTRACTWEBSITE_H
#define ABSTRACTWEBSITE_H

#include "webframework-qt_global.h"
#include "page/PageInterface.h"
#include <httpserver.h>

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
        virtual void publish();
        void addPage(page::PageInterface *page);

    protected:
        AbstractWebsite(AbstractWebsitePrivate *pr, QObject *parent = 0);
        AbstractWebsitePrivate *d_ptr;

        virtual void handleRequest(Tufao::HttpServerRequest &request, Tufao::HttpServerResponse &response) = 0;

    private:
        Q_DECLARE_PRIVATE(AbstractWebsite)
};

}
}

#endif // ABSTRACTWEBSITE_H
