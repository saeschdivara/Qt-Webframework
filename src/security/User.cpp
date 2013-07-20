#include "User.h"

namespace web {
namespace security {

class UserPrivate
{
    public:
        QString name;
        QString password;

        Right right;

        arangodb::Document * doc;
};

User::User(const QString & username, const QString & password, Right right, arangodb::Document * doc) :
    d_ptr(new UserPrivate)
{
    Q_D(User);
    d->name = username;
    d->password = password;
    d->right = right;
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

bool User::hasRight(Right r)
{
    Q_D(User);
    return ((quint16(d->right) & quint16(r)) == quint16(r));
}

arangodb::Document *User::document() const
{
    Q_D(const User);
    return d->doc;
}

}
}
