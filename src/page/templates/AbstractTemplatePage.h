#ifndef ABSTRACTTEMPLATEPAGE_H
#define ABSTRACTTEMPLATEPAGE_H

#include "webframework-qt_global.h"
#include "page/StatefulPageInterface.h"

namespace web
{
namespace page
{
namespace templates
{

class AbstractTemplatePagePrivate;

/**
 * @brief The AbstractTemplatePage class
 *
 * @author Sascha Häusler <saeschdivara@gmail.com>
 * @since 0.2
 */
class WEBFRAMEWORKQTSHARED_EXPORT AbstractTemplatePage : public StatefulPageInterface
{
    public:
        virtual ~AbstractTemplatePage();

        /**
         * @brief Returns the parsed template file
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual QByteArray getContent() Q_DECL_OVERRIDE;

        /**
         * @brief Sets session for the user
         *
         * @param s Session
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void setSession(website::WebSession *s) Q_DECL_OVERRIDE;

        /**
         * @brief Sets request pointer and stores it
         *
         * @param r Request pointer
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void setRequest(Tufao::HttpServerRequest *r) Q_DECL_OVERRIDE;

        /**
         * @brief Stores response pointer
         *
         * @param r Response pointer
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void setResponse(Tufao::HttpServerResponse *r) Q_DECL_OVERRIDE;

        /**
         * @brief Stores the post data
         *
         * @param data Post variables and their values
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void setPostRequestData(QMap<QByteArray, QByteArray> data) Q_DECL_OVERRIDE;

        /**
         * @brief Clears the storage of the post variables
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void clearPostRequestData() Q_DECL_OVERRIDE;

        /**
         * @brief Stores the get data
         *
         * @param data Get variables and their values
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void setGetRequestData(QMap<QByteArray, QByteArray> data) Q_DECL_OVERRIDE;

        /**
         * @brief Clears the storage of the get variables
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void clearGetRequestData() Q_DECL_OVERRIDE;

        /**
         * @brief Stores the request path under which the page
         * is registered
         *
         * @param path Request path
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void setRequestPath(const QString & path) Q_DECL_OVERRIDE;

        /**
         * @brief
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual bool isFileUploadAllowed() Q_DECL_OVERRIDE;
        virtual bool isWaitingForFileUploadToFinish() Q_DECL_OVERRIDE;
        virtual void onFileUploadFinished() Q_DECL_OVERRIDE;

        /**
         * @brief This is the oppotunity to create the models for the page
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void createModels() = 0;

    protected:
        AbstractTemplatePagePrivate *d_ptr;
        AbstractTemplatePage(AbstractTemplatePagePrivate *d);

        /**
         * @brief initPage
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void initPage();

        /**
         * @brief initTemplates
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void initTemplates() = 0;

        /**
         * @brief initTemplate
         *
         * @param name
         * @param filename
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        void initTemplate(QString name, QString filename);

        /**
         * @brief initModels
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void initModels() = 0;

        /**
         * @brief loadModel
         *
         * @param name
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        void loadModel(const QString & name);

        /**
         * @brief destroyModels
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void destroyModels() = 0;

        /**
         * @brief unloadModel
         *
         * @param name
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        void unloadModel(const QString & name);

        /**
         * @brief render
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void render();

    private:
        Q_DECLARE_PRIVATE(AbstractTemplatePage)
};

/**
 * @brief createTemplatePage
 *
 * @param t
 *
 * @return
 *
 * @author Sascha Häusler <saeschdivara@gmail.com>
 * @since 0.2
 */
AbstractTemplatePage * createTemplatePage(AbstractTemplatePage *t);

}
}
}

#endif // ABSTRACTTEMPLATEPAGE_H
