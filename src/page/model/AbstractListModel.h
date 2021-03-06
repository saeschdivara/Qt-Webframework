#ifndef ABSTRACTLISTMODEL_H
#define ABSTRACTLISTMODEL_H

#include "AbstractModel.h"
#include <QtCore/QList>

namespace web
{
namespace page
{
namespace model
{

class WEBFRAMEWORKQTSHARED_EXPORT AbstractListModel : public AbstractModel
{
        Q_OBJECT
    public:
        AbstractListModel(QObject *parent = 0);
        virtual QList<AbstractModel *> models() = 0;
};

}
}
}

#endif // ABSTRACTLISTMODEL_H
