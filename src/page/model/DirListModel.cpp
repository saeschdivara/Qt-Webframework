#include "DirListModel.h"

#include <QtCore/QDebug>
#include <QtCore/QDir>

namespace web
{
namespace page
{
namespace model
{

enum DirFileType {
    NoType,
    ImageType,
    MovieType
    };

#define IF_FILE_TYPE(fileStr, fileEnding, fileType) \
    do { \
    if (fileStr.endsWith(QStringLiteral(fileEnding))) \
            return fileType;\
    } while(0)

DirFileType getFileType(const QString & file) {
    IF_FILE_TYPE(file, ".jpg", DirFileType::ImageType);
    IF_FILE_TYPE(file, ".png", DirFileType::ImageType);
    IF_FILE_TYPE(file, ".gif", DirFileType::ImageType);
    return DirFileType::NoType;
}

DirListModel::DirListModel(const QString & dirPath, const QString & addressPath, QObject *parent) :
    AbstractListModel(parent)
{
    generateAllModels(dirPath, addressPath);
}

void DirListModel::load()
{
    for (int i = m_startPosition; i < m_limit; ++i) {
        AbstractModel * model = m_folderContent.at(i);
        model->load();
    }
}

void DirListModel::unload()
{
    for (int i = m_startPosition; i < m_limit; ++i) {
        AbstractModel * model = m_folderContent.at(i);
        model->unload();
    }

    // Reset start position and limit
    m_startPosition = 0;
    m_limit = m_folderContent.size();
}

void DirListModel::setStartPosition(uint i)
{
    m_startPosition = i;
}

void DirListModel::setLimit(uint i)
{
    m_limit = i;
}

QList<AbstractModel *> DirListModel::models()
{
    return m_folderContent;
}

void DirListModel::generateAllModels(const QString & dirPath, const QString & addressPath)
{
    QDir dir(dirPath);
    dir.setSorting(QDir::Name);
    QStringList folderItems = dir.entryList();
    for (int i = 0; i < folderItems.count(); ++i) {
        QString item = folderItems.at(i);
        DirFileType type = getFileType(item);
        switch (type) {
            case DirFileType::ImageType:
                m_folderContent.append(new ImageModel(item, addressPath));
                break;
            default:
                break;
        }
    }
}

}
}
}
