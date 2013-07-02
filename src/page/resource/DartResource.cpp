#include "DartResource.h"
#include "private/AbstractResource_p.h"

#include <QtCore/QDebug>
#include <QtCore/QProcess>

namespace web
{
namespace page
{
namespace resource
{

class DartResourcePrivate : public AbstractResourcePrivate
{
    public:
        QString dartFileName;
};

const QString DART2JS_SCRIPT = QStringLiteral("../../../../dart/dart-sdk/bin/dart2js");

DartResource::DartResource(const QString &dartFile, const QString &jsFile) :
    AbstractResource(new DartResourcePrivate)
{
    Q_D(DartResource);

    d->fileName = jsFile;
    d->dartFileName = dartFile;

    compileDartFile();
}

void DartResource::compileDartFile()
{
    Q_D(DartResource);
    QStringList arguments;
#ifdef QT_WEBFRAMEWORK_DEBUG
    arguments << QStringLiteral("--checked")
              << QStringLiteral("--out=") + d->fileName
              << d->dartFileName;
#else
#endif

    QProcess::startDetached(DART2JS_SCRIPT, arguments);
}

}
}
}
