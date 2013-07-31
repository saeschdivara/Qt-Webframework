#ifndef SIMPLEPAGE_H
#define SIMPLEPAGE_H

#include "webframework-qt_global.h"
#include "PageInterface.h"
#include <QtCore/QScopedPointer>

namespace web
{
namespace page
{

class SimplePagePrivate;

/**
 * @brief This class is for easy use to return a static page
 *
 * @author Sascha Häusler <saeschdivara@gmail.com>
 * @since 0.2
 */
class WEBFRAMEWORKQTSHARED_EXPORT SimplePage : public PageInterface
{
    public:
        /**
         * @brief SimplePage
         *
         * @param fileName Name of the file which content will be served
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        SimplePage(QString fileName);

        /**
         * @brief The content is the file's content
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual QByteArray getContent() Q_DECL_OVERRIDE;

    protected:
        SimplePage(SimplePagePrivate *pr, QString fileName);
        QScopedPointer<SimplePagePrivate> d_ptr;

    private:
        Q_DECLARE_PRIVATE(SimplePage)
};

}
}

#endif // SIMPLEPAGE_H
