#ifndef ABSTRACTTEMPLATEPAGE_P_H
#define ABSTRACTTEMPLATEPAGE_P_H

#include <httpserverrequest.h>
#include <httpserverresponse.h>
#include <sessionstore.h>
#include <QtCore/QHash>
#include "page/model/AbstractListModel.h"
#include "page/model/AbstractModel.h"

namespace web
{
namespace page
{
namespace templates
{

class AbstractTemplatePagePrivate
{
    public:
        Tufao::SessionStore *session;
        Tufao::HttpServerRequest *request;
        Tufao::HttpServerResponse *response;

        QHash<QByteArray, QByteArray> post;
        QHash<QByteArray, QByteArray> get;

        QHash<QString, QByteArray> templates;

        QString pageFilename;
        QByteArray pageData;

        QByteArray content;

        model::AbstractModel *pageModel;
        QHash<QString, model::AbstractListModel *> templateModels;
};

}
}
}

#endif // ABSTRACTTEMPLATEPAGE_P_H
