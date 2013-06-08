#ifndef ABSTRACTTEMPLATEPAGE_P_H
#define ABSTRACTTEMPLATEPAGE_P_H

#include <httpserverrequest.h>
#include <httpserverresponse.h>
#include <sessionstore.h>

namespace web
{
namespace page
{
namespace templates
{

class AbstractTemplatePagePrivate
{
    public:
        Tufao::SessionStore *session;
        Tufao::HttpServerRequest *request;
        Tufao::HttpServerResponse *response;

        QHash<QByteArray, QByteArray> post;
        QHash<QByteArray, QByteArray> get;

        QHash<QString, QByteArray> templates;

        QString pageFilename;
        QByteArray pageData;

        QByteArray content;
};

}
}
}

#endif // ABSTRACTTEMPLATEPAGE_P_H