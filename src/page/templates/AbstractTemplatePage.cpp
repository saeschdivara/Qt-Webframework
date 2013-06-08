#include "AbstractTemplatePage.h"
#include "private/AbstractTemplatePage_p.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QDir>
#include <QtCore/QFile>

namespace web
{
namespace page
{
namespace templates
{

AbstractTemplatePage::~AbstractTemplatePage()
{
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

    render();

    return d->content;
}

void AbstractTemplatePage::setSession(Tufao::SessionStore *s)
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

void AbstractTemplatePage::setPostRequestData(QHash<QByteArray, QByteArray> data)
{
    Q_D(AbstractTemplatePage);
    d->post = data;
}

void AbstractTemplatePage::setGetRequestData(QHash<QByteArray, QByteArray> data)
{
    Q_D(AbstractTemplatePage);
    d->get = data;
}

AbstractTemplatePage::AbstractTemplatePage(AbstractTemplatePagePrivate *d) :
    d_ptr(d)
{
}

void AbstractTemplatePage::initPage()
{
    Q_D(AbstractTemplatePage);
    QString filepath = QCoreApplication::applicationDirPath() + QDir::separator() + d->pageFilename;
    qDebug() << filepath;
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

}
}
}
