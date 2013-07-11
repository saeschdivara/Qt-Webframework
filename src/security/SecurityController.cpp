#include "SecurityController.h"

#include <Arangodbdriver.h>

#include <QtCore/QCryptographicHash>
#include <QtCore/QDebug>
#include <QtCore/QVariant>

namespace web {
namespace security {

using namespace arangodb;

class SecurityControllerPrivate
{
    public:
        Arangodbdriver * nosql;

        inline QString generateRandomString() {
            return QStringLiteral("");
        }

        inline QString hash(const QString &data, int times) const {
            QByteArray hashedData = data.toUtf8();
            for (int i = 0; i < times; ++i) {
                hashedData = QCryptographicHash::hash(hashedData, QCryptographicHash::Sha3_512);
            }

            return hashedData;
        }

        inline QString hashPassword(const QString &unhashedPw, QString extraString = QString()) {
            QString randomString = (extraString.isEmpty()) ? generateRandomString() : extraString;
            return hash(unhashedPw + randomString, 9) + QStringLiteral("$:4") + randomString;
        }

        inline bool isCorrectUserPassword(const QString & realUserPw, const QString & inputPassword) {
            QStringList splittedPassword = realUserPw.split(QStringLiteral("$:4"));
            QString randomString = splittedPassword.at(1);
            QString userInputPw = hashPassword(inputPassword, randomString);

            qDebug() << userInputPw;

            return realUserPw == userInputPw;
        }
};

const QString WEB_USER_COLLECTION = QString("");

Q_GLOBAL_STATIC(SecurityController, securityInst)

SecurityController::SecurityController() :
    SecurityController(new SecurityControllerPrivate)
{
}

SecurityController *SecurityController::globalInstance()
{
    return securityInst();
}

User *SecurityController::login(const QString & username, const QString & password)
{
    Q_D(SecurityController);
    Document * userDoc = d->nosql->getDocument(WEB_USER_COLLECTION + QStringLiteral("/") + username);
    User * user = Q_NULLPTR;
    QString userPassword = userDoc->get(QStringLiteral("password")).toString();

    if (d->isCorrectUserPassword(userPassword, password)) {
        user = new User(username, userPassword);
    }

    return user;
}

User *SecurityController::registerUser(const QString & username, const QString & password)
{
    Q_D(SecurityController);
    return new User(username, d->hashPassword(password));
}

SecurityController::SecurityController(SecurityControllerPrivate * d) :
    d_ptr(d)
{
    d->nosql = new Arangodbdriver;
}

}
}
