#include "I18nManager.h"

#include <Arangodbdriver.h>
#include <headers.h>
#include <ibytearray.h>

#include <QtCore/QDebug>
#include <QtCore/QHash>

#define I18N_RETURN_IF_LANGUAGE(clientLanguageIf, clientLanguage, returnLanguage) \
    do { \
        if ( clientLanguageIf.contains(clientLanguage, Qt::CaseInsensitive) ) { \
            return returnLanguage; \
        } \
    } while(0)

namespace web
{
namespace internationalisation
{

class I18nManagerPrivate
{
    public:
        arangodb::Arangodbdriver *nosql;
        QHash<QString, LanguageTexts *> allLanguageTexts;
};

const QString I18N_COLLECTION_NAME = QString("i18n");

Q_GLOBAL_STATIC_WITH_ARGS(I18nManager, i18n, ())

I18nManager::I18nManager(QString protocol, QString host, qint32 port) :
    d_ptr(new I18nManagerPrivate)
{
    Q_D(I18nManager);
    d->nosql = new arangodb::Arangodbdriver(protocol, host, port);
}

I18nManager::~I18nManager()
{
    Q_D(I18nManager);
    delete d->nosql;
    qDeleteAll(d->allLanguageTexts);
    delete d;
}

I18nManager *I18nManager::globalInstance()
{
    return i18n();
}

void I18nManager::loadLanguageTexts(const QString &language)
{
    Q_D(I18nManager);
    arangodb::Document *languageText = Q_NULLPTR;

    if (d->allLanguageTexts.contains(language)) {
            LanguageTexts *texts = d->allLanguageTexts.value(language);
            languageText = texts->document();

            languageText->updateStatus();
            I18N_WAIT(languageText);

            if (!languageText->isCurrent()) {
                    languageText->sync();
                    I18N_WAIT(languageText);
                }
        } else {
            languageText = d->nosql->getDocument(I18N_COLLECTION_NAME + QStringLiteral("/") + language);
            I18N_WAIT(languageText);

            // if the language texts don't exist
            if (languageText->hasErrorOccurred()) {
                    // Delete old document
                    languageText->deleteLater();

                    // Create a new document
                    languageText = d->nosql->createDocument(I18N_COLLECTION_NAME, language);

                    languageText->save();
                    I18N_WAIT(languageText);
                }

            // Register the language texts for one language
            d->allLanguageTexts.insert(language, new LanguageTexts(languageText));
        }
}

LanguageTexts *I18nManager::languageTexts(const QString &language)
{
    Q_D(I18nManager);
    return d->allLanguageTexts.value(language);
}

QString I18nManager::text(const QString &language, const QString &key) const
{
    Q_D(const I18nManager);
    if ( d->allLanguageTexts.contains(language) ) {
            LanguageTexts *texts = d->allLanguageTexts.value(language);
            return texts->text(key);
        }
    else {
            return QStringLiteral("");
        }
}

QString I18nManager::requestLanguage(Tufao::HttpServerRequest *request)
{
    if (request->headers().contains(Tufao::IByteArray("Accept-Language"))) {
            QString language = request->headers().value(Tufao::IByteArray("Accept-Language"));

            I18N_RETURN_IF_LANGUAGE(language, QStringLiteral("en-US"), QStringLiteral("en"));
        }

    return QStringLiteral("");

}

}
}
