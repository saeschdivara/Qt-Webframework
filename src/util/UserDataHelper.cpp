#include "UserDataHelper.h"

#include <QtCore/QByteArray>
#include <QtCore/QFile>

namespace web
{
namespace util
{

QByteArray UserDataHelper::readPostFile(const QMap<QByteArray, QByteArray> & postData, const QByteArray & variableName)
{
    QByteArray filePath = postData.value(variableName);
    QFile file(filePath);
    if ( filePath.isEmpty() || !file.open(QIODevice::ReadOnly)) {
        return QByteArray();
    }

    QByteArray data = file.readAll();

    file.close();
    return data;
}

}
}
