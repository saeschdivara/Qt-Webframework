#ifndef WEBSESSION_H
#define WEBSESSION_H

#include "security/User.h"

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
            m_store->removeSession(m_request, m_response);
        }

        inline void setRequest(HttpServerRequest *request) {
            m_request = request;
        }

        inline void setResponse(HttpServerResponse *response) {
            m_response = response;
        }

        inline void setProperty(const QByteArray &key, const QVariant &value) {
            m_store->setProperty(m_request, m_response, key, value);
        }

        inline void removeProperty(const QByteArray &key) {
            m_store->removeProperty(m_request, m_response, key);
        }

        inline QVariant getProperty(const QByteArray &key) const {
            return m_store->property(m_request, m_response, key);
        }

        inline bool hasProperty(const QByteArray &key) const {
            return m_store->hasProperty(m_request, m_response, key);
        }

        inline QList<QByteArray> properties() const {
            return m_store->properties(m_request, m_response);
        }

        inline void setLoggedIn(bool b) {
            setProperty(QByteArrayLiteral("isLoggedIn"), b);
        }

        inline bool isLoggedIn() {
            return hasProperty(QByteArrayLiteral("isLoggedIn"))
                    ? getProperty(QByteArrayLiteral("isLoggedIn")).toBool()
                    : false;
        }

        inline void setUser(security::User * user) {
            m_user = user;
        }

        inline security::User * user() const {
            return m_user;
        }

    private:
        HttpServerRequest *m_request;
        HttpServerResponse *m_response;
        SessionStore *m_store;
        security::User *m_user;
};

}
}

#endif // WEBSESSION_H
