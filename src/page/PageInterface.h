#ifndef PAGEINTERFACE_H
#define PAGEINTERFACE_H

#include "webframework-qt_global.h"
#include <QtCore/QByteArray>

namespace web
{
namespace page
{

/**
 * @brief Every page has to be inhareted from this interface
 *
 * @author Sascha Häusler <saeschdivara@gmail.com>
 * @since 0.2
 */
class WEBFRAMEWORKQTSHARED_EXPORT PageInterface
{
    public:
        /**
         * @brief ~PageInterface
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual ~PageInterface() {}

        /**
         * @brief This is the method which is called at the very end of every
         * request and delivers the content which is returned by the server
         *
         * @return The content of the page which is returned by the response
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual QByteArray getContent() = 0;
};

}
}

#endif // PAGEINTERFACE_H
