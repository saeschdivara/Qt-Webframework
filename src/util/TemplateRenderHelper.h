#ifndef TEMPLATERENDERHELPER_H
#define TEMPLATERENDERHELPER_H

#include "../page/model/AbstractListModel.h"

#include <QtCore/QVariant>
#include <QtXml/QDomElement>

namespace web
{
namespace util
{

/**
 * @brief The TemplateRenderHelper class
 *
 * @author Sascha Häusler <saeschdivara@gmail.com>
 * @since 0.3
 */
class WEBFRAMEWORKQTSHARED_EXPORT TemplateRenderHelper
{
    public:
        /**
         * @brief This method enables to either use a model property or a real
         * value for a specific template attribute and decide which as which
         * type it is returned.
         *
         * @param ele   Dom element which holds the template informations
         * @param attr  Attribute name of the dom element
         * @param model Model which could hold the property for the attribute
         *
         * @return Returns the dom attribute as the wanted type
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        template<class T>
        static T getTemplateAttribute(QDomElement & ele, const QString & attr, web::page::model::AbstractModel *model) {
            QString domAttribute = ele.attribute(attr);
            if (domAttribute.startsWith('$') && domAttribute.endsWith('$')) {
                T v = model->property(domAttribute.remove('$').toUtf8().data()).value<T>();
                return v;
            }

            return QVariant(domAttribute).value<T>();
        }

        /**
         * @brief Through the model attribute it can be decided if the user
         * can see what the template would generate or not.
         *
         * @param ifAttribute   Model attribute which has to be either true or false
         * @param model         Model which holds the attribute
         *
         * @return If the model has a valid attribute it will be returned, otherwise false
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        static bool isTemplateAllowed(QString ifAttribute, web::page::model::AbstractModel *model);

        /**
         * @brief getTrimmedTemplate
         *
         * @param tag
         * @param templateContent
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        static QByteArray getTrimmedTemplate(const QString & tag, QByteArray templateContent);

        /**
         * @brief This method replaces every placeholder which has to be like this:
         * $place_holder_name$. The placeholdername has to match a Qt object property.
         * Thanks to the property method the method replaces every placeholder, if they don't
         * exists with an empty space.
         *
         * @param pageContent   The content which contains the template in which the placeholders are replaced
         * @param model         Model which holds the properties for the template
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        static void replaceModelPlaceholders(QString &pageContent, web::page::model::AbstractModel *model);

    private:
        TemplateRenderHelper();
};

}
}

#endif // TEMPLATERENDERHELPER_H
