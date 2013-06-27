#include "AbstractTemplatePage.h"
#include "private/AbstractTemplatePage_p.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtXml/QDomDocument>

namespace web
{
namespace page
{
namespace templates
{

AbstractTemplatePage::~AbstractTemplatePage()
{
    Q_D(AbstractTemplatePage);

    delete d->pageModel;
    qDeleteAll(d->templateModels);

    delete d_ptr;
}

QByteArray AbstractTemplatePage::getContent()
{
    Q_D(AbstractTemplatePage);

    if ( d->pageData.isEmpty() ) {
            initPage();
        }

    if ( d->templates.isEmpty() ) {
            initTemplates();
        }

    initModels();

    render();

    destroyModels();

    return d->content;
}

void AbstractTemplatePage::setSession(website::WebSession *s)
{
    Q_D(AbstractTemplatePage);
    d->session = s;
}

void AbstractTemplatePage::setRequest(Tufao::HttpServerRequest *r)
{
    Q_D(AbstractTemplatePage);
    d->request = r;
}

void AbstractTemplatePage::setResponse(Tufao::HttpServerResponse *r)
{
    Q_D(AbstractTemplatePage);
    d->response = r;
}

void AbstractTemplatePage::setPostRequestData(QMap<QByteArray, QByteArray> data)
{
    Q_D(AbstractTemplatePage);
    d->post = data;
}

void AbstractTemplatePage::clearPostRequestData()
{
    Q_D(AbstractTemplatePage);
    d->post.clear();
}

void AbstractTemplatePage::setGetRequestData(QMap<QByteArray, QByteArray> data)
{
    Q_D(AbstractTemplatePage);
    d->get = data;
}

void AbstractTemplatePage::clearGetRequestData()
{
    Q_D(AbstractTemplatePage);
    d->get.clear();
}

AbstractTemplatePage::AbstractTemplatePage(AbstractTemplatePagePrivate *d) :
    d_ptr(d)
{
}

void AbstractTemplatePage::initPage()
{
    Q_D(AbstractTemplatePage);
    QString filepath = QCoreApplication::applicationDirPath() + QDir::separator() + d->pageFilename;
    QFile f(filepath);
    if ( f.open(QIODevice::ReadOnly) ) {
            QByteArray data = f.readAll();
            d->pageData = data;
            f.close();
        }
    else {
            qDebug() << f.errorString();
        }
}

void AbstractTemplatePage::initTemplate(QString name, QString filename)
{
    QFile f(filename);
    if ( f.open(QIODevice::ReadOnly) ) {
            Q_D(AbstractTemplatePage);
            QByteArray data = f.readAll();
            d->templates.insert(name, data);
            f.close();
        }
    else {
            qDebug() << f.errorString();
        }
}

void AbstractTemplatePage::render()
{
    Q_D(AbstractTemplatePage);

    QDomDocument doc;
    QString errMsg;
    int errLine, errColumn;
    doc.setContent(d->pageData, false, &errMsg, &errLine, &errColumn);

    QDomNodeList templates = doc.elementsByTagName("tpl");
    const int templateSize = templates.size();
    // We need to go backwards because otherwise the deleting of nodes doesnt work
    for (int i = templateSize-1; i >= 0 ; --i) {
            QDomElement element = templates.item(i).toElement();
            QDomNode parentNode = element.parentNode();

            if (element.hasAttribute("src")) {
                    QString tplName = element.attribute("src");
                    bool isAllowedToShow = true;

                    if (element.hasAttribute("if")) {
                            QString ifAttribute = element.attribute("if");
                            isAllowedToShow = d->isTemplateAllowed(ifAttribute, d->pageModel);
                        }
                    else if (element.hasAttribute("if-not")) {
                            QString ifAttribute = element.attribute("if-not");
                            isAllowedToShow = !d->isTemplateAllowed(ifAttribute, d->pageModel);
                        }

                    if (isAllowedToShow) {

                            QString templateStartTag = QStringLiteral("<tpl>");
                            QString templateEndTag = QStringLiteral("</tpl>");
                            QString templateContent = d->templates[tplName].replace(templateStartTag, "").replace(templateEndTag, "");
                            QString templateFilled;

                            if (element.hasAttribute("model")) {
                                    QString modelName = element.attribute("model");
                                    web::page::model::AbstractListModel *model = d->templateModels[modelName];
                                    model->load();
                                    QList<web::page::model::AbstractModel *> modelList = model->models();
                                    QString modelIfAttribute;

                                    if (element.hasAttribute("if-model")) {
                                            modelIfAttribute = element.attribute("if-model");
                                        }

                                    for (int i = 0; i < modelList.size(); ++i) {
                                            QString modelTemplate = templateContent;
                                            web::page::model::AbstractModel *templateModel = modelList.at(i);

                                            if (d->isTemplateAllowed(modelIfAttribute, templateModel)) {
                                                    d->replaceModelPlaceholders(modelTemplate, templateModel);
                                                    templateFilled += modelTemplate;
                                                }

                                            model->unload();
                                        }
                                } else {
                                    templateFilled = templateContent;
                                }

                            templateFilled = templateStartTag + templateFilled + templateEndTag;
                            QDomDocument tplDoc;
                            tplDoc.setContent(templateFilled, false, &errMsg, &errLine, &errColumn);

                            parentNode.replaceChild(tplDoc.documentElement(), element);
                        } else {
                            parentNode.removeChild(element);
                        }
                }
            else {
                    parentNode.removeChild(element);
                }
        }

    QString content = doc.toString();
    d->replaceModelPlaceholders(content, d->pageModel);

    d->content = content.toUtf8();
}

}
}
}
