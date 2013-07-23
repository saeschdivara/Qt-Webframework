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
        ~AbstractWebsite();

        virtual void publish();
        void addPage(QString name, page::PageInterface *page);
        void addImageFolder(QString name, QString folder);
        void addFolderWithImageFolders(const QString & name, const QString & folder);

    protected:
        AbstractWebsite(AbstractWebsitePrivate *pr, QObject *parent = 0);
        AbstractWebsitePrivate *d_ptr;

        virtual void initPages() = 0;
        virtual void handleRequest(Tufao::HttpServerRequest *request, Tufao::HttpServerResponse *response);

    private:
        Q_DECLARE_PRIVATE(AbstractWebsite)
};

}
}

#endif // ABSTRACTWEBSITE_H
