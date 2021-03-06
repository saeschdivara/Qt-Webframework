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

        template<class T>
        T getTemplateAttribute(QDomElement & ele, const QString & attr, web::page::model::AbstractModel *model) {
            QString domAttribute = ele.attribute(attr);
            if (domAttribute.startsWith('$') && domAttribute.endsWith('$')) {
                T v = model->property(domAttribute.remove('$').toUtf8().data()).value<T>();
                return v;
            }

            return QVariant(domAttribute).value<T>();
        }

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
