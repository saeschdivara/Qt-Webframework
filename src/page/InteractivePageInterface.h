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
class WEBFRAMEWORKQTSHARED_EXPORT InteractivePageInterface
{
    public:
        /**
         * @brief ~InteractivePageInterface
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual ~InteractivePageInterface() {}

        /**
         * @brief ajaxMimeType
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual QByteArray ajaxMimeType() = 0;

        /**
         * @brief ajaxContent
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual QByteArray getAjaxContent() = 0;
};

}
}

#endif // INTERACTIVEPAGEINTERFACE_H
