#include "AbstractTranslatableTemplate.h"
#include "private/AbstractTranslatableTemplate_p.h"
#include "internationalisation/I18nManager.h"

namespace web
{
namespace page
{
namespace templates
{

void AbstractTranslatableTemplate::setRequest(Tufao::HttpServerRequest *r)
{
    Q_D(AbstractTranslatableTemplate);
    d->clientLanguage = internationalisation::I18nManager::globalInstance()->requestLanguage(r);
    AbstractTemplatePage::setRequest(r);
}

AbstractTranslatableTemplate::AbstractTranslatableTemplate(AbstractTranslatableTemplatePrivate *d) :
    AbstractTemplatePage(d)
{
}

model::AbstractTranslatableModel *AbstractTranslatableTemplate::initTranslatableModel(model::AbstractTranslatableModel *model)
{
    Q_D(AbstractTranslatableTemplate);
    model->setLanguage(d->clientLanguage);
    return model;
}

}
}
}
