#include "AbstractResource.h"
#include "private/AbstractResource_p.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QFile>

namespace web
{
namespace page
{
namespace resource
{

AbstractResource::~AbstractResource()
{
    delete d_ptr;
}

void AbstractResource::setResponse(Tufao::HttpServerResponse *response)
{
    Q_D(AbstractResource);
    d->response = response;
}

QByteArray AbstractResource::getContent()
{
    Q_D(AbstractResource);

    QFile file(d->fileName);
    if (file.open(QIODevice::ReadOnly)) {
            QByteArray data;
            data.resize(2000);

            while (!file.atEnd()) {
                    data = file.read(2000);
                    d->response->write(data);
                    qApp->processEvents();
                }

            file.close();
        }

    return QByteArrayLiteral("");
}

AbstractResource::AbstractResource(AbstractResourcePrivate *d) :
    d_ptr(d)
{
}

}
}
}
