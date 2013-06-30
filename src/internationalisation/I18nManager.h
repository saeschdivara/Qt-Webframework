#ifndef I18NMANAGER_H
#define I18NMANAGER_H

#include "webframework-qt_global.h"
#include "LanguageTexts.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QGlobalStatic>
#include <QtCore/QString>

#define I18N_OUTPUT_WAIT(doc) \
    do { \
        if ( doc->hasErrorOccurred() )  \
            qDebug() << doc->errorMessage();\
    } while(0)

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
        I18N_OUTPUT_WAIT(doc); \
    } while(0)

namespace web
{
namespace internationalisation
{

class I18nManagerPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT I18nManager
{
    public:
        /**
         * @brief I18nManager
         *
         * @param protocol
         * @param host
         * @param port
         *
         * @since 0.4
         */
        I18nManager(QString protocol = QString("http"),
                    QString host = QString("localhost"),
                    qint32 port = 8529);

        ~I18nManager();

        /**
         * @brief globalInstance
         *
         * @return
         *
         * @since 0.4
         */
        static I18nManager* globalInstance();

        /**
         * @brief loadLanguageTexts
         *
         * @param language
         *
         * @since 0.4
         */
        void loadLanguageTexts(const QString &language);

        /**
         * @brief languageTexts
         *
         * @param language
         *
         * @return
         *
         * @since 0.4
         */
        LanguageTexts *languageTexts(const QString &language);

        /**
         * @brief text
         *
         * @param language
         * @param key
         *
         * @return
         *
         * @since 0.4
         */
        QString text(const QString &language, const QString &key) const;

    protected:
        I18nManagerPrivate *d_ptr;

    private:
        Q_DECLARE_PRIVATE(I18nManager)
};

}
}

#endif // I18NMANAGER_H
