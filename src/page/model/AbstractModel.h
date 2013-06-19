#ifndef ABSTRACTPAGEMODEL_H
#define ABSTRACTPAGEMODEL_H

#include <QObject>

namespace web
{
namespace page
{
namespace model
{

class AbstractModel : public QObject
{
        Q_OBJECT
    public:
        explicit AbstractModel(QObject *parent = 0);

        virtual void load() = 0;
        virtual void unload() = 0;
};

}
}
}

#endif // ABSTRACTPAGEMODEL_H
