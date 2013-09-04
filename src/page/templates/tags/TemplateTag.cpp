#include "TemplateTag.h"
#include "private/TagInterfacePrivate.h"

#include "TagRenderer.h"

#include <util/TemplateRenderHelper.h>

namespace web
{
namespace page
{
namespace templates
{
namespace tags
{

class TemplateTagPrivate : public TagInterfacePrivate
{
    public:
        TagRenderer * renderer;

        inline QString getTemplateName() {
            QString templateName = element.attribute("src");
            return templateName;
        }

        inline QByteArray getTemplate() {
            if ( content.isEmpty() ) {
                QString templateName = getTemplateName();
                return util::TemplateRenderHelper::getTrimmedTemplate(tagName, templates[templateName]);
            }
            else {
                return content;
            }
        }
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

void TemplateTag::setTemplateList(QHash<QString, QByteArray> templates)
{
    Q_D(TemplateTag);
    d->templates = templates;
}

void TemplateTag::setTemplateRenderer(TagRenderer * renderer)
{
    Q_D(TemplateTag);
    d->renderer = renderer;
}

bool TemplateTag::isContentAllowed()
{
    Q_D(TemplateTag);
    return d->isContentAllowed;
}

void TemplateTag::render()
{
    Q_D(TemplateTag);

    d->isContentAllowed = true;

    // We need a src attribute
    if ( !d->attributes.contains("src") && d->content.isEmpty() ) {
        d->isContentAllowed = false;
        return;
    }

    // If the tag has an if-attribute, the page models
    // property with the if-attribute is checked
    if ( d->attributes.contains("if") ) {
        QString ifAttribute = util::TemplateRenderHelper::getTemplateAttribute<QString>(
                    d->element,
                    QString("if"),
                    d->pageModel
                    );

        d->isContentAllowed = util::TemplateRenderHelper::isTemplateAllowed(ifAttribute, d->pageModel);
        if ( !d->isContentAllowed ) return;
    }
    else if ( d->attributes.contains("if-not") ) {
        QString ifNotAttribute = util::TemplateRenderHelper::getTemplateAttribute<QString>(
                    d->element,
                    QString("if-not"),
                    d->pageModel
                    );

        d->isContentAllowed = !util::TemplateRenderHelper::isTemplateAllowed(ifNotAttribute, d->pageModel);
        if ( !d->isContentAllowed ) return;
    }

    QByteArray templateContent = d->getTemplate();

    // If there is no model to work with, we just
    // use the template without any replacements
    if (  !d->attributes.contains("model") ) {
        d->content = templateContent;
        return;
    }

    QString listModelName = d->element.attribute("model");
    model::AbstractListModel * listModel = d->templateModels[listModelName];
    QList<web::page::model::AbstractModel *> modelList = listModel->models();

    QString modelIfAttribute;
    int modelCountAttribute = -1;
    int modelStartCountAttribute = -1;

    bool hasIfAttribute = false;

    if (d->element.hasAttribute("if-model")) {
        modelIfAttribute = d->element.attribute("if-model");
        hasIfAttribute = true;
    }

    if (d->element.hasAttribute("model-start-count")) {
        modelStartCountAttribute = util::TemplateRenderHelper::getTemplateAttribute<int>(d->element,
                                                                                         "model-start-count",
                                                                                         d->pageModel
                                                                                         );
    }

    if (d->element.hasAttribute("model-count")) {
        modelCountAttribute = util::TemplateRenderHelper::getTemplateAttribute<int>(d->element,
                                                                                    "model-count",
                                                                                    d->pageModel);
    }

    if ( modelStartCountAttribute < 0 ) {
        modelStartCountAttribute = 0;
    }

    if ( modelCountAttribute <= 0 ) {
        modelCountAttribute  = modelList.size();
    }
    else {
        modelCountAttribute = modelStartCountAttribute + modelCountAttribute;
    }

    const int maxCount = modelList.size();

    for (int i = modelStartCountAttribute; i < modelCountAttribute && i < maxCount; ++i) {
        QString modelTemplate = templateContent;
        web::page::model::AbstractModel *templateModel = modelList.at(i);

        if ( !hasIfAttribute || util::TemplateRenderHelper::isTemplateAllowed(modelIfAttribute, templateModel) ) {
            util::TemplateRenderHelper::replaceModelPlaceholders(modelTemplate, templateModel);
            modelTemplate = d->renderer->renderSubTag(modelTemplate, QLatin1String("if"), templateModel);
            d->content += modelTemplate;
        }
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
