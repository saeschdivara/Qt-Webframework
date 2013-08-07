#include "TemplateRenderHelper.h"

#include <QRegularExpression>

namespace web
{
namespace util
{

bool TemplateRenderHelper::isTemplateAllowed(QString ifAttribute, page::model::AbstractModel * model)
{
    QVariant ifProperty = model->property(ifAttribute.toUtf8().data());
    if (ifProperty.isValid()) {
        return ifProperty.toBool();
    }

    return false;
}

QByteArray TemplateRenderHelper::getTrimmedTemplate(const QString & tag, QByteArray templateContent)
{
    QString startTag("<%1>");
    QString endTag("</%1>");

    templateContent.replace(startTag.arg(tag), "");
    templateContent.replace(endTag.arg(tag), "");

    return templateContent;
}

void TemplateRenderHelper::replaceModelPlaceholders(QString & pageContent, page::model::AbstractModel * model)
{
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

}
}
