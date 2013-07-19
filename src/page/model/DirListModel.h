#ifndef DIRLISTMODEL_H
#define DIRLISTMODEL_H

#include "AbstractListModel.h"
#include "ImageModel.h"

namespace web
{
namespace page
{
namespace model
{

class WEBFRAMEWORKQTSHARED_EXPORT DirListModel : public AbstractListModel
{
        Q_OBJECT
    public:
        explicit DirListModel(const QString & dirPath, const QString & addressPath, QObject *parent = 0);

        virtual void load() Q_DECL_OVERRIDE;
        virtual void unload() Q_DECL_OVERRIDE;

        virtual QList<AbstractModel *> models() Q_DECL_OVERRIDE;

    protected:
        void generateAllModels(const QString & dirPath, const QString & addressPath);

    private:
        QList<AbstractModel *> m_folderContent;
};

}
}
}

#endif // DIRLISTMODEL_H
