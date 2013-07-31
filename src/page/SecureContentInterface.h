#ifndef SECURECONTENTINTERFACE_H
#define SECURECONTENTINTERFACE_H

#include "webframework-qt_global.h"

namespace web {
namespace page {

/**
 * @brief If a page's access has to be checked
 * this interface has to be implemented
 *
 * @author Sascha Häusler <saeschdivara@gmail.com>
 * @since 0.2
 */
class WEBFRAMEWORKQTSHARED_EXPORT SecureContentInterface
{
    public:
        /**
         * @brief ~SecureContentInterface
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual ~SecureContentInterface() {}

        /**
         * @brief Returns true if the user can access this page
         *
         * @return If returns false the user is access denied
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual bool isUserAllowedToSeeThisContent() = 0;
};

}
}

#endif // SECURECONTENTINTERFACE_H
