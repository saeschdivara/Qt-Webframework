#ifndef TEMPLATETAG_H
#define TEMPLATETAG_H

#include "TagInterface.h"

namespace web
{
namespace page
{
namespace templates
{
namespace tags
{

class TemplateTagPrivate;

/**
 * @brief The TemplateTag class
 *
 * @author Sascha Häusler <saeschdivara@gmail.com>
 * @since 0.3
 */
class TemplateTag : public TagInterface
{
        // TagInterface interface
    public:
        TemplateTag();

        /**
         * @brief Returns tpl
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual QString tag() const Q_DECL_OVERRIDE;

        /**
         * @brief Doesn't store the content because there shouldn't
         * be any.
         *
         * @param content
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void setTagContent(const QByteArray & content) Q_DECL_OVERRIDE;

        /**
         * @brief The following attributes are used:
         * - src
         * - if
         * - if-not
         * - model
         * - if-model
         * - model-start-count
         * - model-count
         *
         * @param attributes
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void setElement(QDomElement element) Q_DECL_OVERRIDE;

        /**
         * @brief If the page model is needed, with this method it
         * can be saved
         *
         * @param pageModel
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void setPageModel(model::AbstractModel * pageModel) Q_DECL_OVERRIDE;

        /**
         * @brief setModelList
         *
         * @param templateModels
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void setModelList(QHash<QString, model::AbstractListModel *> templateModels) Q_DECL_OVERRIDE;

        /**
         * @brief With this method all templates which the page
         * contains are set
         *
         * @param templates
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void setTemplateList(QHash<QString, QByteArray> templates) Q_DECL_OVERRIDE;

        /**
         * @brief Only if this method returns true, the content
         * is shown in the page
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual bool isContentAllowed() Q_DECL_OVERRIDE;

        /**
         * @brief Renders the attributes and generates the content
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void render() Q_DECL_OVERRIDE;

        /**
         * @brief Returns the generated content
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual QByteArray getRenderedContent() Q_DECL_OVERRIDE;

    protected:
        TemplateTagPrivate * d_ptr;
        TemplateTag(TemplateTagPrivate * d);

    private:
        Q_DECLARE_PRIVATE(TemplateTag)
};

}
}
}
}

#endif // TEMPLATETAG_H
