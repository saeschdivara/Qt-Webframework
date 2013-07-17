#include "ImageModel.h"

namespace web
{
namespace page
{
namespace model
{

ImageModel::ImageModel(const QString & path, QObject *parent) :
    AbstractModel(parent)
{
    m_filePath = path;
}

void ImageModel::load()
{
}

void ImageModel::unload()
{
}

}
}
}
