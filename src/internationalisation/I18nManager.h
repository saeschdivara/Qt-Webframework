#ifndef I18NMANAGER_H
#define I18NMANAGER_H

#include <QtCore/QGlobalStatic>
#include <QtCore/QString>

namespace web
{
namespace internationalisation
{

class I18nManagerPrivate;

class I18nManager
{
    public:
        I18nManager(QString protocol = QString("http"),
                    QString host = QString("localhost"),
                    qint32 port = 8529);

        ~I18nManager();

        static I18nManager* globalInstance();

        void loadLanguageTexts(QString language);

    protected:
        I18nManagerPrivate *d_ptr;

    private:
        Q_DECLARE_PRIVATE(I18nManager)
};

}
}

#endif // I18NMANAGER_H
