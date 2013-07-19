#ifndef DIRLISTMAPMODEL_H
#define DIRLISTMAPMODEL_H

#include "DirListModel.h"

#include <QtCore/QHash>

namespace web
{
namespace page
{
namespace model
{

class WEBFRAMEWORKQTSHARED_EXPORT DirListMapModel : public AbstractListModel
{
        Q_OBJECT
    public:
        explicit DirListMapModel(const QString & dirPath, const QString & addressPath, QObject *parent = 0);

        virtual void load() Q_DECL_OVERRIDE;
        virtual void unload() Q_DECL_OVERRIDE;

        virtual QList<AbstractModel *> models() Q_DECL_OVERRIDE;

        void setModelListName(const QString & name) {
            m_loadingModelsName = name;
        }

    protected:
        void generateAllModels(const QString & dirPath, const QString & addressPath);

    private:
        QHash<QString, AbstractListModel *> m_listModels;
        QString m_loadingModelsName;
};

}
}
}

#endif // DIRLISTMAPMODEL_H
