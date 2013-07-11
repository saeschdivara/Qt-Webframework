#ifndef SECURITYCONTROLLER_H
#define SECURITYCONTROLLER_H

#include "webframework-qt_global.h"
#include <QtCore/QString>

#include "User.h"

namespace web {
namespace security {

class SecurityControllerPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT SecurityController
{
    public:
        SecurityController();
        SecurityController * globalInstance();

        User * login(const QString & username, const QString & password);
        User * registerUser(const QString & username, const QString & password);

    protected:
        SecurityController(SecurityControllerPrivate * d);
        SecurityControllerPrivate *d_ptr;

    private:
        Q_DECLARE_PRIVATE(SecurityController)
};

}
}

#endif // SECURITYCONTROLLER_H
