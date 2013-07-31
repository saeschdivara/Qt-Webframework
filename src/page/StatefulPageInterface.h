#ifndef STATEFULPAGEINTERFACE_H
#define STATEFULPAGEINTERFACE_H

#include "webframework-qt_global.h"
#include "PageInterface.h"
#include "website/WebSession.h"

#include <QtCore/QHash>

namespace web
{
namespace page
{

/**
 * @brief This interface describes what methods are available for
 * a page which wants to have different states depending on the user
 *
 * @author Sascha Häusler <saeschdivara@gmail.com>
 * @since 0.2
 */
class WEBFRAMEWORKQTSHARED_EXPORT StatefulPageInterface : public PageInterface
{
    public:
        /**
         * @brief Through the request the session is already
         * determened so the pointer to the session has only to be saved
         * so it can be used later
         *
         * @param s Session which holds all the information regarding the user
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void setSession(website::WebSession *s) = 0;

        /**
         * @brief You can set the user request
         *
         * @param r This is the original request object
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void setRequest(Tufao::HttpServerRequest *r) = 0;

        /**
         * @brief You can set the server response
         *
         * @param r This is the object which serves to deliver the response
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void setResponse(Tufao::HttpServerResponse *r) = 0;

        /**
         * @brief If the request has sent any post data this is the time
         * to set them for the page
         *
         * @param data This is a key-value store
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void setPostRequestData(QMap<QByteArray, QByteArray> data) = 0;

        /**
         * @brief If there are no post data in the request, this method
         * is called which gives you the chance to clear the data store
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void clearPostRequestData() = 0;

        /**
         * @brief If the request has sent any get data this is the time
         * to set them for the page
         *
         * @param data This is a key-value store
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void setGetRequestData(QMap<QByteArray, QByteArray> data) = 0;

        /**
         * @brief If there are no get data in the request, this method
         * is called which gives you the chance to clear the data store
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void clearGetRequestData() = 0;

        /**
         * @brief If you need to know what the request path is for this page
         * you can set it by this method
         *
         * @param path The request path for this page
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void setRequestPath(const QString & path) = 0;

        /**
         * @brief This method is only called if a file is uploaded.
         * If this returns true the file is saved
         *
         * @return If true the uploaded file is saved
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual bool isFileUploadAllowed() = 0;

        /**
         * @brief If you want to let the user wait until his file is uploaded
         * than you return true. If you return false than after the file is uploaded
         * @link onFileUploadFinished is triggered
         *
         * @return If true the user has to wait
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual bool isWaitingForFileUploadToFinish() = 0;

        /**
         * @brief This method is only called after a file is uploaded
         * and @link isWaitingForFileUploadToFinish returns false
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void onFileUploadFinished() = 0;
};

}
}

#endif // STATEFULPAGEINTERFACE_H
