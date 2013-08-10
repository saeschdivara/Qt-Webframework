#ifndef USERDATAHELPER_H
#define USERDATAHELPER_H

#include "webframework-qt_global.h"
#include <QtCore/QMap>

namespace web
{
namespace util
{

/**
 * @brief This helper class is to use the post and get data
 * much easier.
 *
 * @author Sascha Häusler <saeschdivara@gmail.com>
 * @since 0.3
 */
class WEBFRAMEWORKQTSHARED_EXPORT UserDataHelper
{
    public:
        /**
         * @brief Reads the file and returns the its data. If the
         * file or the variable shouldn't exist, it will return an empty QByteArray.
         *
         * @param postData      Post data map which contains the file path
         * @param variableName  Variable name
         *
         * @return File data
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        static QByteArray readPostFile(const QMap<QByteArray, QByteArray> & postData, const QByteArray & variableName);

    private:
        UserDataHelper();
};

}
}

#endif // USERDATAHELPER_H
