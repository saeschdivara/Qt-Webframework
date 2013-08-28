#include "AbstractTemplatePage.h"
#include "private/AbstractTemplatePage_p.h"
#include "util/TemplateRenderHelper.h"

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

#ifdef QT_WEBFRAMEWORK_DEBUG
    initPage();
    initTemplates();
#else
    if ( d->pageData.isEmpty() ) {
            initPage();
        }

    if ( d->templates.isEmpty() ) {
            initTemplates();
        }
#endif

    initModels();

    preRender();
    render();
    afterRender();

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

void AbstractTemplatePage::setRequestPath(const QString & path)
{
    Q_D(AbstractTemplatePage);
    d->requestPath = path;
}

bool AbstractTemplatePage::isFileUploadAllowed()
{
    return false;
}

bool AbstractTemplatePage::isWaitingForFileUploadToFinish()
{
    return false;
}

void AbstractTemplatePage::onFileUploadFinished()
{
    return; // Do nothing
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
            qDebug() << Q_FUNC_INFO << f.errorString();
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
            qDebug() << Q_FUNC_INFO << f.errorString();
    }
}

void AbstractTemplatePage::loadModel(const QString & name)
{
    Q_D(AbstractTemplatePage);
    model::AbstractListModel * model = d->templateModels.value(name);
    model->load();
}

void AbstractTemplatePage::unloadModel(const QString & name)
{
    Q_D(AbstractTemplatePage);
    model::AbstractListModel * model = d->templateModels.value(name);
    model->unload();
}

void AbstractTemplatePage::render()
{
    Q_D(AbstractTemplatePage);

    d->renderer.setContent(d->pageData);
    d->renderer.setPageModel(d->pageModel);
    d->renderer.setModelList(d->templateModels);
    d->renderer.setTemplateList(d->templates);

    QString content = d->renderer.render();
    util::TemplateRenderHelper::replaceModelPlaceholders(content, d->pageModel);

    d->content = content.toUtf8();
}

AbstractTemplatePage *createTemplatePage(AbstractTemplatePage *t)
{
    t->createModels();
    return t;
}

}
}
}
