#ifndef LANGUAGETEXTS_H
#define LANGUAGETEXTS_H

#include "webframework-qt_global.h"
#include <Document.h>

namespace web
{
namespace internationalisation
{

class LanguageTextsPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT LanguageTexts
{
    public:
        LanguageTexts(arangodb::Document *doc);
        ~LanguageTexts();

        QString text(const QString &key) const;
        arangodb::Document* document() const;

    protected:
        LanguageTextsPrivate *d_ptr;
        LanguageTexts(LanguageTextsPrivate *d, arangodb::Document *doc);

    private:
        Q_DECLARE_PRIVATE(LanguageTexts)
};

}
}

#endif // LANGUAGETEXTS_H
