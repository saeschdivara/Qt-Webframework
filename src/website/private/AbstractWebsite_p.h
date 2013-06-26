#ifndef ABSTRACTWEBSITE_P_H
#define ABSTRACTWEBSITE_P_H

#include "page/PageInterface.h"
#include "website/WebSession.h"

#include <httpserver.h>
#include <httpserverrequest.h>
#include <httpserverresponse.h>
#include <simplesessionstore.h>

#include <QtCore/QHash>
#include <QtCore/QScopedPointer>
#include <QtCore/QUrl>

namespace web {
namespace website {

class AbstractWebsitePrivate
{
public:
        QUrl url;
        QHash<QString ,page::PageInterface *> pages;
        QScopedPointer<Tufao::HttpServer> server;
        Tufao::SimpleSessionStore sessionStore;

        WebSession *session(Tufao::HttpServerRequest *request, Tufao::HttpServerResponse *response) {
            if (sessionStore.hasSession(*request)) {
                } else {
                }
        }
};

}
}

#endif // ABSTRACTWEBSITE_P_H
