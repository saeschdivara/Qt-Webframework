#include "SimplePage.h"

namespace web {
namespace page {

class SimplePagePrivate
{
    public:
        QString fileName;
};

SimplePage::SimplePage(QString fileName) :
    SimplePage(new SimplePagePrivate, fileName)
{
}

QByteArray SimplePage::getContent() const
{
    return QByteArray();
}

SimplePage::SimplePage(SimplePagePrivate *pr, QString fileName) :
    d_ptr(pr)
{
    Q_D(SimplePage);
    d->fileName = fileName;
}

}
}
