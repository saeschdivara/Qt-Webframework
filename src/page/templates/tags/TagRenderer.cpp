#include "TagRenderer.h"
#include "TemplateTag.h"

#include <QtCore/QDebug>
#include <QtCore/QStringList>

namespace web
{
namespace page
{
namespace templates
{
namespace tags
{

class TagRendererPrivate
{
    public:
        QByteArray content;
        model::AbstractModel * pageModel;
        QHash<QString, model::AbstractListModel *> templateModels;
        QHash<QString, QByteArray> templates;

        QStringList getTags(QDomDocumentType docType) {
            Q_UNUSED(docType);
            QStringList tags;
            tags << "tpl";

            return tags;
        }

        tags::TagInterface * getTagObjectForTagString(const QString & tagString) {
            if ( tagString == "tpl" ) return new TemplateTag;

            return Q_NULLPTR;
        }
};

TagRenderer::TagRenderer() :
    d_ptr(new TagRendererPrivate)
{
}

TagRenderer::~TagRenderer()
{
    delete d_ptr;
}

void TagRenderer::setContent(QByteArray content)
{
    Q_D(TagRenderer);
    d->content = content;
}

void TagRenderer::setPageModel(model::AbstractModel * pageModel)
{
    Q_D(TagRenderer);
    d->pageModel = pageModel;
}

void TagRenderer::setModelList(QHash<QString, model::AbstractListModel *> templateModels)
{
    Q_D(TagRenderer);
    d->templateModels = templateModels;
}

void TagRenderer::setTemplateList(QHash<QString, QByteArray> templates)
{
    Q_D(TagRenderer);
    d->templates = templates;
}

QString TagRenderer::render()
{
    Q_D(TagRenderer);
    QDomDocument doc;

    doc.setContent(d->content);

    QDomDocumentType docType = doc.doctype();
    QStringList tags = d->getTags(docType);

    for ( QString tagString : tags ) {
        TagInterface * tag = d->getTagObjectForTagString(tagString);
        if ( tag ) {
            QDomNodeList tagNodeList = doc.elementsByTagName(tagString);
            const int tagListSize = tagNodeList.size();

            tag->setPageModel(d->pageModel);

            // We need to go backwards because otherwise the deleting of nodes doesnt work
            for (int i = tagListSize-1; i >= 0 ; --i) {
                QDomElement element = tagNodeList.item(i).toElement();
                QDomNode parentNode = element.parentNode();

                tag->setTagContent(element.text());
                tag->setElement(element);
                tag->setModelList(d->templateModels);
                tag->setTemplateList(d->templates);

                tag->render();

                if ( tag->isContentAllowed() ) {
                    QByteArray renderedTagContent = tag->getRenderedContent();
                    QString newTag("<%1>%2</%1>");
                    newTag.arg(tagString).arg(renderedTagContent);

                    QDomDocument tagDoc;
                    tagDoc.setContent(newTag.toUtf8());
                    parentNode.replaceChild(tagDoc.documentElement(), element);
                }
                else {
                    parentNode.removeChild(element);
                }
            }

            delete tag;
        }
    }

    return doc.toString();
}

}
}
}
}
