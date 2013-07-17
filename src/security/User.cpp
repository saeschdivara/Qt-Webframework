#include "User.h"

namespace web {
namespace security {

class UserPrivate
{
    public:
        QString name;
        QString password;

        arangodb::Document * doc;
};

User::User(const QString & username, const QString & password, arangodb::Document * doc) :
    d_ptr(new UserPrivate)
{
    Q_D(User);
    d->name = username;
    d->password = password;
    d->doc = doc;
}

QString User::name() const
{
    Q_D(const User);
    return d->name;
}

QString User::password() const
{
    Q_D(const User);
    return d->password;
}

arangodb::Document *User::document() const
{
    Q_D(const User);
    return d->doc;
}

}
}
