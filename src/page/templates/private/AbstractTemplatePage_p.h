#ifndef ABSTRACTTEMPLATEPAGE_P_H
#define ABSTRACTTEMPLATEPAGE_P_H

#include "page/model/AbstractListModel.h"
#include "page/model/AbstractModel.h"
#include "website/WebSession.h"

#include <httpserverrequest.h>
#include <httpserverresponse.h>
#include <sessionstore.h>

#include <QtCore/QDebug>
#include <QtCore/QHash>
#include <QtCore/QMetaMethod>
#include <QtCore/QMetaObject>

#include <QtXml/QDomElement>
#include <QRegularExpression>

namespace web
{
namespace page
{
namespace templates
{

/**
 * @brief The AbstractTemplatePagePrivate class
 *
 * @author Sascha Häusler <saeschdivara@gmail.com>
 * @since 0.2
 */
class AbstractTemplatePagePrivate
{
    public:
        website::WebSession *session;
        Tufao::HttpServerRequest *request;
        Tufao::HttpServerResponse *response;

        QMap<QByteArray, QByteArray> post;
        QMap<QByteArray, QByteArray> get;

        QHash<QString, QByteArray> templates;

        QString pageFilename;
        QString requestPath;
        QByteArray pageData;

        QByteArray content;

        model::AbstractModel *pageModel;
        QHash<QString, model::AbstractListModel *> templateModels;

        /**
         * @brief Checks if there were any post variables in the request
         *
         * @return Returns true if the request had any post variables
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        bool hasPostVariables() {
            return post.isEmpty();
        }

        /**
         * @brief Checks if there were any get variables in the request
         *
         * @return Returns true if the request had any get variables
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        bool hasGetVariables() {
            return get.isEmpty();
        }

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
         * @since 0.2
         */
        void replaceModelPlaceholders(QString &pageContent, web::page::model::AbstractModel *model) {
            QRegularExpression regex("\\$(.*)\\$");
            QRegularExpressionMatchIterator matchIterator = regex.globalMatch(pageContent);
            while ( matchIterator.hasNext() ) {
                    QRegularExpressionMatch match = matchIterator.next();
                    QString toReplacingString = match.captured(0);
                    QString placeholderName = match.captured(1);

                    QString replacingString = model->property(placeholderName.toUtf8().data()).toString();
                    pageContent.replace(toReplacingString, replacingString);
                }
        }

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
         * @since 0.2
         */
        template<class T>
        T getTemplateAttribute(QDomElement & ele, const QString & attr, web::page::model::AbstractModel *model) {
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
         * @since 0.2
         */
        bool isTemplateAllowed(QString ifAttribute, web::page::model::AbstractModel *model) {
            QVariant ifProperty = model->property(ifAttribute.toUtf8().data());
            if (ifProperty.isValid()) {
                    return ifProperty.toBool();
                }

            return false;
        }
};

}
}
}

#endif // ABSTRACTTEMPLATEPAGE_P_H
