#include "AbstractTranslatableModel.h"
#include "internationalisation/I18nManager.h"

namespace web
{
namespace page
{
namespace model
{

void AbstractTranslatableModel::setLanguage(const QString &lang)
{
    m_language = lang;
}

AbstractTranslatableModel::AbstractTranslatableModel(QObject *parent) :
    AbstractModel(parent)
{
}

QString AbstractTranslatableModel::_t(const char *key)
{
    return internationalisation::I18nManager::globalInstance()->text(m_language, key);
}

}
}
}
