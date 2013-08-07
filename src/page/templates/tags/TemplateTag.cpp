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
        QDomElement element;
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

QString TemplateTag::tag() const
{
    Q_D(const TemplateTag);
    return d->tagName;
}

void TemplateTag::setTagContent(const QByteArray & content)
{
    Q_UNUSED(content); // There shouldn't be any
}

void TemplateTag::setElement(QDomElement element)
{
    Q_D(TemplateTag);
    d->element = element;
    d->attributes = element.attributes();
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

    QString templateName = d->element.attribute("src");

    if ( d->attributes.contains("if") ) {
        QString ifAttribute = util::TemplateRenderHelper::getTemplateAttribute<QString>(
                    d->element,
                    "if",
                    d->pageModel
                    );

        d->isContentAllowed = util::TemplateRenderHelper::isTemplateAllowed(ifAttribute, d->pageModel);
        if ( !d->isContentAllowed ) return;
    }
    else if ( d->attributes.contains("if-not") ) {
        QString ifNotAttribute = util::TemplateRenderHelper::getTemplateAttribute<QString>(
                    d->element,
                    "if-not",
                    d->pageModel
                    );

        d->isContentAllowed = util::TemplateRenderHelper::isTemplateAllowed(ifNotAttribute, d->pageModel);
        if ( !d->isContentAllowed ) return;
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
