#ifndef USER_H
#define USER_H

#include "webframework-qt_global.h"

namespace web {
namespace security {

class UserPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT User
{
    public:
        User();

    protected:
        UserPrivate *d_ptr;

    private:
        Q_DECLARE_PRIVATE(User)
};

}
}

#endif // USER_H
