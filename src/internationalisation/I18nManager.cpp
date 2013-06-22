#include "I18nManager.h"
#include <Arangodbdriver.h>

namespace web
{
namespace internationalisation
{

class I18nManagerPrivate
{
    public:
        arangodb::Arangodbdriver *nosql;
};

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
    delete d;
}

I18nManager *I18nManager::globalInstance()
{
    return i18n();
}

void I18nManager::loadLanguageTexts(QString language)
{
}

}
}
