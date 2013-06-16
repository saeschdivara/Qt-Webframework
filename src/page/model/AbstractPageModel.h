#ifndef ABSTRACTPAGEMODEL_H
#define ABSTRACTPAGEMODEL_H

#include <QObject>

class AbstractPageModel : public QObject
{
        Q_OBJECT
    public:
        explicit AbstractPageModel(QObject *parent = 0);
        
    signals:
        
    public slots:
        
};

#endif // ABSTRACTPAGEMODEL_H
