#ifndef ABSTRACTRENDEREDPAGE_P_H
#define ABSTRACTRENDEREDPAGE_P_H

#include "htmlelement/AbstractHtmlElement.h"
#include <QtCore/QByteArray>
#include <httpserverrequest.h>
#include <httpserverresponse.h>
#include <sessionstore.h>

namespace web {
namespace page {

class AbstractRenderedPagePrivate
{
    public:
        QByteArray data;
        Tufao::SessionStore *session;
        Tufao::HttpServerRequest *request;
        Tufao::HttpServerResponse *response;
        htmlelement::AbstractHtmlElement *root = Q_NULLPTR;
};

}
}

#endif // ABSTRACTRENDEREDPAGE_P_H
