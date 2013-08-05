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
        /**
         * @brief Returns tpl
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual QString &tag() const;

        /**
         * @brief Doesn't store the content because there shouldn't
         * be any.
         *
         * @param content
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void setTagContent(const QByteArray & content);

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
        virtual void setAttributes(QDomNamedNodeMap attributes);

        /**
         * @brief Renders the attributes and generates the content
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void render();

        /**
         * @brief Returns the generated content
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual QByteArray getRenderedContent();
};

}
}
}
}

#endif // TEMPLATETAG_H
