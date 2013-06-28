#ifndef I18NMANAGER_H
#define I18NMANAGER_H

#include <QtCore/QCoreApplication>
#include <QtCore/QGlobalStatic>
#include <QtCore/QString>

#define I18N_WAIT(doc) \
    do { \
        bool b = true; \
        QMetaObject::Connection conn1 = QObject::connect(doc, &arangodb::Document::ready, [&] { \
                b = false; \
            });\
        QMetaObject::Connection conn2 = QObject::connect(doc, &arangodb::Document::error, [&] { \
                b = false; \
            }); \
        while (b) { \
                qApp->processEvents(); \
            } \
        QObject::disconnect(conn1); \
        QObject::disconnect(conn2); \
    } while(0)

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
