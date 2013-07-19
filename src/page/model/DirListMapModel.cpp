#include "DirListMapModel.h"

#include <QtCore/QDebug>
#include <QtCore/QDir>

namespace web
{
namespace page
{
namespace model
{

DirListMapModel::DirListMapModel(const QString & dirPath, const QString & addressPath, QObject *parent) :
    AbstractListModel(parent)
{
    generateAllModels(dirPath, addressPath);
}

void DirListMapModel::load()
{
    AbstractListModel * model = m_listModels.value(m_loadingModelsName);
    model->load();
}

void DirListMapModel::unload()
{
    AbstractListModel * model = m_listModels.value(m_loadingModelsName);
    model->unload();
}

QList<AbstractModel *> DirListMapModel::models()
{
    AbstractListModel * model = m_listModels.value(m_loadingModelsName);
    return model->models();
}

void DirListMapModel::generateAllModels(const QString & dirPath, const QString & addressPath)
{
    QDir dir(dirPath);
    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
    QStringList allFiles = dir.entryList();
    for ( QString dir : allFiles ) {
            QString entry = addressPath + QDir::separator() + dir + QDir::separator();
            QString path = dirPath + dir;
            AbstractListModel * model = new DirListModel(path, entry);
            m_listModels.insert(entry, model);
    }
}

}
}
}
