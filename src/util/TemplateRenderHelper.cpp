#include "TemplateRenderHelper.h"

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

template<class T>
T TemplateRenderHelper::getTemplateAttribute(QDomElement & ele, const QString & attr, page::model::AbstractModel * model)
{
    QString domAttribute = ele.attribute(attr);
    if (domAttribute.startsWith('$') && domAttribute.endsWith('$')) {
        T v = model->property(domAttribute.remove('$').toUtf8().data()).value<T>();
        return v;
    }

    return QVariant(domAttribute).value<T>();
}

}
}
