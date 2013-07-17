#ifndef USER_H
#define USER_H

#include "webframework-qt_global.h"
#include "Document.h"

#include <QtCore/QString>

namespace web {
namespace security {

class UserPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT User
{
    public:
        User(const QString & username, const QString & password, arangodb::Document * doc);

        QString name() const;
        QString password() const;

        arangodb::Document * document() const;

    protected:
        UserPrivate *d_ptr;

    private:
        Q_DECLARE_PRIVATE(User)
};

}
}

#endif // USER_H
