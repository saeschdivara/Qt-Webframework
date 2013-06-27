#ifndef WEBSESSION_H
#define WEBSESSION_H

#include <httpserverrequest.h>
#include <httpserverresponse.h>
#include <sessionstore.h>

#include <QtCore/QVariant>

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

        ~WebSession() {
            m_store->removeSession(*m_request, *m_response);
        }

        inline void setProperty(const QByteArray &key, const QVariant &value) {
            m_store->setProperty(*m_request, *m_response, key, value);
        }

        inline QVariant getProperty(const QByteArray &key) const {
            return m_store->property(*m_request, *m_response, key);
        }

        inline void removeProperty(const QByteArray &key) {
            m_store->removeProperty(*m_request, *m_response, key);
        }

        inline QList<QByteArray> properties() const {
            return m_store->properties(*m_request, *m_response);
        }

    private:
        HttpServerRequest *m_request;
        HttpServerResponse *m_response;
        SessionStore *m_store;
};

}
}

#endif // WEBSESSION_H
