#ifndef ABSTRACTPAGEMODEL_H
#define ABSTRACTPAGEMODEL_H

#include "webframework-qt_global.h"
#include <QObject>

namespace web
{
namespace page
{
namespace model
{

class WEBFRAMEWORKQTSHARED_EXPORT AbstractModel : public QObject
{
        Q_OBJECT
    public:
        virtual void load() = 0;
        virtual void unload() = 0;

    protected:
        AbstractModel(QObject *parent = 0);
};

}
}
}

#endif // ABSTRACTPAGEMODEL_H
