#include "ImageModel.h"

#include <QDebug>
#include <QtCore/QDir>
#include <QtCore/QFile>

namespace web
{
namespace page
{
namespace model
{

ImageModel::ImageModel(const QString & path, const QString & webaddressPath, QObject *parent) :
    AbstractModel(parent)
{
    m_filePath = path;
    m_webPath = webaddressPath;
}

void ImageModel::load()
{
    int pos = m_filePath.lastIndexOf(QDir::separator());
    m_name = m_webPath + m_filePath.right(m_filePath.length() - pos);
}

void ImageModel::unload()
{
}

}
}
}
