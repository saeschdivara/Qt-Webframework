#ifndef ABSTRACTTEMPLATEPAGE_P_H
#define ABSTRACTTEMPLATEPAGE_P_H

#include "page/model/AbstractListModel.h"
#include "page/model/AbstractModel.h"
#include "page/templates/tags/TagRenderer.h"
#include "website/WebSession.h"

#include <httpserverrequest.h>
#include <httpserverresponse.h>
#include <sessionstore.h>

#include <QtCore/QDebug>
#include <QtCore/QHash>

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

        tags::TagRenderer renderer;

        /**
         * @brief Checks if there were any post variables in the request
         *
         * @return Returns true if the request had any post variables
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        inline bool hasPostVariables() {
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
        inline bool hasGetVariables() {
            return get.isEmpty();
        }
};

}
}
}

#endif // ABSTRACTTEMPLATEPAGE_P_H
