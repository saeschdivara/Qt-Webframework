#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include "AbstractModel.h"

namespace web
{
namespace page
{
namespace model
{

class WEBFRAMEWORKQTSHARED_EXPORT ImageModel : public AbstractModel
{
        Q_OBJECT
        Q_PROPERTY(QString name MEMBER m_name)
    public:
        explicit ImageModel(const QString & path, const QString & webaddressPath, QObject *parent = 0);

        virtual void load() Q_DECL_OVERRIDE;
        virtual void unload() Q_DECL_OVERRIDE;

    protected:
        QString m_filePath;
        QString m_webPath;
        QString m_name;
};

}
}
}

#endif // IMAGEMODEL_H
