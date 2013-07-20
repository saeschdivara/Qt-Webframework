#ifndef SECURECONTENTINTERFACE_H
#define SECURECONTENTINTERFACE_H

#include "webframework-qt_global.h"

namespace web {
namespace page {

class WEBFRAMEWORKQTSHARED_EXPORT SecureContentInterface
{
    public:
        virtual ~SecureContentInterface() {}

        virtual bool isUserAllowedToSeeThisContent() = 0;
};

}
}

#endif // SECURECONTENTINTERFACE_H
