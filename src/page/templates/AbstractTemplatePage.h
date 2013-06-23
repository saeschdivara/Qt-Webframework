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

class WEBFRAMEWORKQTSHARED_EXPORT AbstractTemplatePage : public StatefulPageInterface
{
    public:
        virtual ~AbstractTemplatePage();

        /**
         * @brief
         *
         * @return
         */
        virtual QByteArray getContent() Q_DECL_OVERRIDE;

        virtual void setSession(Tufao::SessionStore *s) Q_DECL_OVERRIDE;
        virtual void setRequest(Tufao::HttpServerRequest *r) Q_DECL_OVERRIDE;
        virtual void setResponse(Tufao::HttpServerResponse *r) Q_DECL_OVERRIDE;

        virtual void setPostRequestData(QMap<QByteArray, QByteArray> data) Q_DECL_OVERRIDE;
        virtual void setGetRequestData(QMap<QByteArray, QByteArray> data) Q_DECL_OVERRIDE;

        virtual void createModels() = 0;

    protected:
        AbstractTemplatePagePrivate *d_ptr;
        AbstractTemplatePage(AbstractTemplatePagePrivate *d);

        virtual void initPage();

        virtual void initTemplates() = 0;
        void initTemplate(QString name, QString filename);

        virtual void initModels() = 0;
        virtual void destroyModels() = 0;

        virtual void render();

    private:
        Q_DECLARE_PRIVATE(AbstractTemplatePage)
};

}
}
}

#endif // ABSTRACTTEMPLATEPAGE_H
