#ifndef INTERACTIVEPAGEINTERFACE_H
#define INTERACTIVEPAGEINTERFACE_H

#include "webframework-qt_global.h"
#include "StatefulPageInterface.h"

namespace web
{
namespace page
{

/**
 * @brief The InteractivePageInterface class
 *
 * @author Sascha Häusler <saeschdivara@gmail.com>
 * @since 0.2
 */
class WEBFRAMEWORKQTSHARED_EXPORT InteractivePageInterface : public StatefulPageInterface
{
    public:
        /**
         * @brief ~InteractivePageInterface
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual ~InteractivePageInterface() {}
};

}
}

#endif // INTERACTIVEPAGEINTERFACE_H
