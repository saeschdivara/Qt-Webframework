#ifndef ABSTRACTTRANSLATABLEMODEL_H
#define ABSTRACTTRANSLATABLEMODEL_H

#include "AbstractModel.h"

namespace web
{
namespace page
{
namespace model
{

class WEBFRAMEWORKQTSHARED_EXPORT AbstractTranslatableModel : public AbstractModel
{
        Q_OBJECT
    public:
        void setLanguage(const QString &lang);

    protected:
        AbstractTranslatableModel(QObject *parent = 0);

        QString _t(const char *key);

        QString m_language;
};

}
}
}

#endif // ABSTRACTTRANSLATABLEMODEL_H
