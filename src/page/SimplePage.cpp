#include "SimplePage.h"
#include <QtCore/QFile>

namespace web {
namespace page {

class SimplePagePrivate
{
    public:
        QFile file;
        QByteArray data;
};

SimplePage::SimplePage(QString fileName) :
    SimplePage(new SimplePagePrivate, fileName)
{
}

SimplePage::~SimplePage()
{
    Q_D(SimplePage);
    d->file.close();
}

QByteArray SimplePage::getContent()
{
    Q_D(SimplePage);

    if ( !d->file.isOpen() ) {
            d->file.open( QIODevice::ReadOnly );
        }

    return d->file.readAll();
}

SimplePage::SimplePage(SimplePagePrivate *pr, QString fileName) :
    d_ptr(pr)
{
    Q_D(SimplePage);
    d->file.setFileName(fileName);

}

}
}
