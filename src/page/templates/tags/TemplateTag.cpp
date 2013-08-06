#include "TemplateTag.h"
#include <util/TemplateRenderHelper.h>

namespace web
{
namespace page
{
namespace templates
{
namespace tags
{

class TemplateTagPrivate
{
    public:
        QString tagName;
        QDomNamedNodeMap attributes;
        QHash<QString, model::AbstractListModel *> templateModels;
        model::AbstractModel * pageModel;
        QByteArray content;
        bool isContentAllowed;
};

TemplateTag::TemplateTag() :
    TemplateTag(new TemplateTagPrivate)
{
}

QString &TemplateTag::tag() const
{
    Q_D(const TemplateTag);
    return d->tagName;
}

void TemplateTag::setAttributes(QDomNamedNodeMap attributes)
{
    Q_D(TemplateTag);
    d->attributes = attributes;
}

void TemplateTag::setPageModel(model::AbstractModel * pageModel)
{
    Q_D(TemplateTag);
    d->pageModel = pageModel;
}

void TemplateTag::setModelList(QHash<QString, model::AbstractListModel *> templateModels)
{
    Q_D(TemplateTag);
    d->templateModels = templateModels;
}

bool TemplateTag::isContentAllowed()
{
    Q_D(TemplateTag);
    return d->isContentAllowed;
}

void TemplateTag::render()
{
    Q_D(TemplateTag);

    // We need a src attribute
    if ( !d->attributes.contains("src") ) {
        d->isContentAllowed = false;
        return;
    }
}

QByteArray TemplateTag::getRenderedContent()
{
    Q_D(TemplateTag);
    return d->content;
}

TemplateTag::TemplateTag(TemplateTagPrivate * d) :
    d_ptr(d)
{
    d->tagName = "tpl";
}

}
}
}
}
