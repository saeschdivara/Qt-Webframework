#include "LanguageTexts.h"

#include <QtCore/QVariant>

namespace web
{
namespace internationalisation
{

class LanguageTextsPrivate
{
    public:
        arangodb::Document *document;
};

LanguageTexts::LanguageTexts(arangodb::Document *doc) :
    LanguageTexts(new LanguageTextsPrivate, doc)
{
}

LanguageTexts::~LanguageTexts()
{
    Q_D(LanguageTexts);
    d->document->deleteLater();
    delete d;
}

QString LanguageTexts::text(const QString &key) const
{
    Q_D(const LanguageTexts);
    return d->document->get(key).toString();
}

arangodb::Document *LanguageTexts::document() const
{
    Q_D(const LanguageTexts);
    return d->document;
}

LanguageTexts::LanguageTexts(LanguageTextsPrivate *d, arangodb::Document *doc) :
    d_ptr(d)
{
    d->document = doc;
}

}
}
