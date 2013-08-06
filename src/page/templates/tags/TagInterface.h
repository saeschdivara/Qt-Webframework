#ifndef TAGINTERFACE_H
#define TAGINTERFACE_H

#include "webframework-qt_global.h"
#include "../../model/AbstractListModel.h"
#include "../../model/AbstractModel.h"

#include <QtXml/QDomNamedNodeMap>

namespace web
{
namespace page
{
namespace templates
{
namespace tags
{

/**
 * @brief The TagInterface class
 *
 * @author Sascha Häusler <saeschdivara@gmail.com>
 * @since 0.3
 */
class WEBFRAMEWORKQTSHARED_EXPORT TagInterface
{
    public:
        /**
         * @brief This method is supposed to return
         * the tag name like "br"
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual QString & tag() const = 0;

        /**
         * @brief This method is here to save the dom attributes
         *
         * @param attributes
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void setAttributes(QDomNamedNodeMap attributes) = 0;

        /**
         * @brief This method is to save the content between
         * the tags like <b>content</b>
         *
         * @param content
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void setTagContent(const QByteArray & content) = 0;

        /**
         * @brief If the page model is needed, with this method it
         * can be saved
         *
         * @param pageModel
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void setPageModel(model::AbstractModel * pageModel) = 0;

        /**
         * @brief setModelList
         *
         * @param templateModels
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void setModelList(QHash<QString, model::AbstractListModel *> templateModels) = 0;

        /**
         * @brief Only if this method returns true, the content
         * is shown in the page
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual bool isContentAllowed() = 0;

        /**
         * @brief Renderes what the content shall be in the
         * page content after the attributes and the content
         * are set
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void render() = 0;

        /**
         * @brief This method should return the rendered tag content
         * with its start and end tag
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual QByteArray getRenderedContent() = 0;
};

}
}
}
}

#endif // TAGINTERFACE_H
