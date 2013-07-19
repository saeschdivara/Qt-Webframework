#ifndef ABSTRACTRENDEREDPAGE_P_H
#define ABSTRACTRENDEREDPAGE_P_H

#include "htmlelement/AbstractHtmlElement.h"
#include "website/WebSession.h"

#include <QtCore/QByteArray>
#include <QtCore/QMap>

#include <httpserverrequest.h>
#include <httpserverresponse.h>
#include <sessionstore.h>

namespace web {
namespace page {

class AbstractRenderedPagePrivate
{
    public:
        QByteArray data;

        website::WebSession *session;
        Tufao::HttpServerRequest *request;
        Tufao::HttpServerResponse *response;

        htmlelement::AbstractHtmlElement *root = Q_NULLPTR;

        QMap<QByteArray, QByteArray> post;
        QMap<QByteArray, QByteArray> get;

        QString requestPath;
};

}
}

#endif // ABSTRACTRENDEREDPAGE_P_H
