#ifndef STATEFULPAGEINTERFACE_H
#define STATEFULPAGEINTERFACE_H

#include "webframework-qt_global.h"
#include "PageInterface.h"
#include "website/WebSession.h"

#include <QtCore/QHash>

namespace web
{
namespace page
{

class WEBFRAMEWORKQTSHARED_EXPORT StatefulPageInterface : public PageInterface
{
    public:
        virtual void setSession(website::WebSession *s) = 0;
        virtual void setRequest(Tufao::HttpServerRequest *r) = 0;
        virtual void setResponse(Tufao::HttpServerResponse *r) = 0;

        virtual void setPostRequestData(QMap<QByteArray, QByteArray> data) = 0;
        virtual void clearPostRequestData() = 0;

        virtual void setGetRequestData(QMap<QByteArray, QByteArray> data) = 0;
        virtual void clearGetRequestData() = 0;

        virtual void setRequestPath(const QString & path) = 0;

        virtual bool isFileUploadAllowed() = 0;
        virtual bool isWaitingForFileUploadToFinish() = 0;
};

}
}

#endif // STATEFULPAGEINTERFACE_H
