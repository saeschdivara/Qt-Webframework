#include "SecurityController.h"

#include <Arangodbdriver.h>
#include <QueryBuilder.h>
#include <QBSelect.h>
#include <QBCursor.h>

#include <QtCore/QCryptographicHash>
#include <QtCore/QDebug>
#include <QtCore/QVariant>

#include <random>
#include <functional>

namespace web {
namespace security {

using namespace arangodb;

class SecurityControllerPrivate
{
    public:
        Arangodbdriver * nosql;

        std::random_device rng;
        QString characters;
        std::uniform_int_distribution<int> dist;
        std::function<int(void)>  generator;
        std::mt19937 engine;

        SecurityControllerPrivate() :
            dist(std::uniform_int_distribution<int>(0, 70)),
            engine(rng())
        {
            characters = QStringLiteral("abcdefghijklmnopqrstvwxyzABCDEFGHIJKLMNOPQRSTVWXYZ1234567890$_-?⁺*%&/()=");
            generator = std::bind(dist, engine);
        }

        inline QString generateRandomString(const int number) {
            QString randomString;
            for (int i = 0; i < number; ++i) {
                QChar randomChar = characters[generator()];
                randomString.append(randomChar);
            }

            return randomString;
        }

        inline QString hash(const QString &data, int times) const {
            QByteArray hashedData = data.toUtf8();
            for (int i = 0; i < times; ++i) {
                hashedData = QCryptographicHash::hash(hashedData, QCryptographicHash::Sha3_512);
            }

            return hashedData;
        }

        inline QString hashPassword(const QString &unhashedPw, QString extraString = QString()) {
            QString randomString = (extraString.isEmpty()) ? generateRandomString(50) : extraString;
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

const QString WEB_USER_COLLECTION = QString("webuser");

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
    QueryBuilder qb;
    QSharedPointer<QBSelect> select = qb.createSelect(WEB_USER_COLLECTION, 1);
    select->setWhere(QStringLiteral("username"), username);
    QSharedPointer<QBCursor> cursor = d->nosql->executeSelect(select);
    cursor->waitForResult();

    if (cursor->count() == 0) {
        return Q_NULLPTR;
    }

    Document * userDoc = cursor->data().first();
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
