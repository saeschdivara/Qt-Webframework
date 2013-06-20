#ifndef ABSTRACTTEMPLATEPAGE_P_H
#define ABSTRACTTEMPLATEPAGE_P_H

#include "page/model/AbstractListModel.h"
#include "page/model/AbstractModel.h"

#include <httpserverrequest.h>
#include <httpserverresponse.h>
#include <sessionstore.h>
#include <QtCore/QHash>

#include <QRegularExpression>

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


        void replaceModelPlaceholders(QString &pageContent, web::page::model::AbstractModel *model) {
            QRegularExpression regex("\\$(.*)\\$");
            QRegularExpressionMatchIterator matchIterator = regex.globalMatch(pageContent);
            while ( matchIterator.hasNext() ) {
                    QRegularExpressionMatch match = matchIterator.next();
                    QString toReplacingString = match.captured(0);
                    QString placeholderName = match.captured(1);

                    QString replacingString = model->property(placeholderName.toLatin1().data()).toString();
                    pageContent.replace(toReplacingString, replacingString);
                }
        }
};

}
}
}

#endif // ABSTRACTTEMPLATEPAGE_P_H
