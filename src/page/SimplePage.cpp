#include "SimplePage.h"

#include <QtCore/QDebug>
#include <QtCore/QFile>
#include <QtCore/QTimer>
#include <QtCore/QCoreApplication>

namespace web {
namespace page {

class SimplePagePrivate
{
    public:
        QFile file;
        QByteArray data;
        QTimer timer;
};

const qint32 CACHE_INTERVAL = 1000 * 60 * 60;

SimplePage::SimplePage(QString fileName) :
    SimplePage(new SimplePagePrivate, fileName)
{
}

QByteArray SimplePage::getContent()
{
    Q_D(SimplePage);

#ifdef QT_WEBFRAMEWORK_DEBUG
    if ( !d->file.open( QIODevice::ReadOnly ) ) {
        qWarning() << Q_FUNC_INFO << "Couldn't open the file: " << d->file.fileName();
        return QByteArrayLiteral("");
    }

    while ( !d->file.atEnd() ) {
            d->data.append(d->file.read(2000));
            QCoreApplication::processEvents();
        }

    d->file.close();
#else
    if ( d->data.isEmpty() ) {
            d->file.open( QIODevice::ReadOnly );

            while ( !d->file.atEnd() ) {
                    d->data.append(d->file.read(800));
                    QCoreApplication::processEvents();
                }

            d->file.close();

            d->timer.setInterval( CACHE_INTERVAL );

            QObject::connect( &d->timer, &QTimer::timeout, [=]() {
                    d->data.clear();
                });

            d->timer.start();
        }
#endif

    return d->data;
}

SimplePage::SimplePage(SimplePagePrivate *pr, QString fileName) :
    d_ptr(pr)
{
    Q_D(SimplePage);
    d->file.setFileName(fileName);
}

}
}
