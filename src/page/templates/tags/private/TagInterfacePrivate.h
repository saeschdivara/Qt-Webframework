#ifndef TAGINTERFACEPRIVATE_H
#define TAGINTERFACEPRIVATE_H

#include <page/model/AbstractListModel.h>

#include <QtCore/QString>
#include <QtCore/QHash>
#include <QtXml/QDomElement>

namespace web
{
namespace page
{
namespace templates
{
namespace tags
{

class TagInterfacePrivate
{
    public:
        QString tagName;
        QDomElement element;
        QDomNamedNodeMap attributes;
        QHash<QString, model::AbstractListModel *> templateModels;
        QHash<QString, QByteArray> templates;
        model::AbstractModel * pageModel;
        QByteArray content;
        bool isContentAllowed;
};

}
}
}
}

#endif // TAGINTERFACEPRIVATE_H
