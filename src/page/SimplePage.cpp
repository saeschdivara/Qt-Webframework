#include "SimplePage.h"
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
