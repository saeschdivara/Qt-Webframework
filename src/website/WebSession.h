#ifndef WEBSESSION_H
#define WEBSESSION_H

#include <httpserverrequest.h>
#include <httpserverresponse.h>
#include <sessionstore.h>

namespace web {
namespace website {

using namespace Tufao;

class WebSession
{
    public:
        inline WebSession(HttpServerRequest *request, HttpServerResponse *response, SessionStore *store) :
            m_request(request),
            m_response(response),
            m_store(store)
        {
        }

    private:
        HttpServerRequest *m_request;
        HttpServerResponse *m_response;
        SessionStore *m_store;
};

}
}

#endif // WEBSESSION_H
