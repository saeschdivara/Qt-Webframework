#ifndef I18NMANAGER_H
#define I18NMANAGER_H

#include "webframework-qt_global.h"
#include "LanguageTexts.h"

#include <httpserverrequest.h>

#include <QtCore/QCoreApplication>
#include <QtCore/QGlobalStatic>
#include <QtCore/QString>

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

        /**
         * @brief requestLanguage
         *
         * @param request
         *
         * @return
         *
         * @since 0.4
         */
        QString requestLanguage(Tufao::HttpServerRequest *request);

    protected:
        I18nManagerPrivate *d_ptr;

    private:
        Q_DECLARE_PRIVATE(I18nManager)
};

}
}

#endif // I18NMANAGER_H
