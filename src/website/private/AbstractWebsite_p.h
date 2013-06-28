#ifndef ABSTRACTWEBSITE_P_H
#define ABSTRACTWEBSITE_P_H

#include "page/PageInterface.h"
#include "website/WebSession.h"

#include <httpserver.h>
#include <httpserverrequest.h>
#include <httpserverresponse.h>
#include <simplesessionstore.h>

#include <QtCore/QDebug>
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
        QHash<QString, WebSession *> sessions;

        inline WebSession *session(Tufao::HttpServerRequest *request, Tufao::HttpServerResponse *response) {
            QString peerAddress = request->socket()->peerAddress().toString();

            if (sessions.contains(peerAddress)) {
                    WebSession *s = sessions.value(peerAddress);
                    s->setRequest(request);
                    s->setResponse(response);

                    return s;
                } else {
                    WebSession *s = new WebSession(request, response, &sessionStore);
                    sessions.insert(peerAddress, s);
                    return s;
                }
        }
};

}
}

#endif // ABSTRACTWEBSITE_P_H
