#include "User.h"

namespace web {
namespace security {

class UserPrivate
{
    public:
};

User::User() :
    d_ptr(new UserPrivate)
{
}

}
}
