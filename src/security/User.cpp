#include "User.h"

namespace web {
namespace security {

class UserPrivate
{
    public:
        QString name;
        QString password;
};

User::User(const QString & username, const QString & password) :
    d_ptr(new UserPrivate)
{
    Q_D(User);
    d->name = username;
    d->password = password;
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

}
}
