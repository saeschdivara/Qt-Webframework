#ifndef TAGRENDERER_H
#define TAGRENDERER_H

#include "TagInterface.h"

namespace web
{
namespace page
{
namespace templates
{
namespace tags
{

class TagRendererPrivate;

/**
 * @brief This is a helper class which makes it
 * easier to use custom tags in the html templates
 * and render them
 *
 * @author Sascha Häusler <saeschdivara@gmail.com>
 * @since 0.3
 */
class WEBFRAMEWORKQTSHARED_EXPORT TagRenderer
{
    public:
        TagRenderer();
        ~TagRenderer();

        /**
         * @brief Set the whole template file content
         *
         * @param content Content which will be rendered
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        void setContent(QByteArray content);

        /**
         * @brief Set the page model
         *
         * @param pageModel
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        void setPageModel(model::AbstractModel * pageModel);

        /**
         * @brief Set model list
         *
         * @param templateModels
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        void setModelList(QHash<QString, model::AbstractListModel *> templateModels);

        /**
         * @brief Set template list from the page
         *
         * @param templates
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        void setTemplateList(QHash<QString, QByteArray> templates);

        /**
         * @brief Renders the content and returns the
         * new content
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        QString render();

        /**
         * @brief renderSubTag
         *
         * @param templateContent
         * @param tag
         * @param model
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        QString renderSubTag(const QString & templateContent, const QString & tagString, model::AbstractModel * model);

    protected:
        TagRendererPrivate * d_ptr;

    private:
        Q_DECLARE_PRIVATE(TagRenderer)
};

}
}
}
}

#endif // TAGRENDERER_H
