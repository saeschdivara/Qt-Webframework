#ifndef ABSTRACTTRANSLATABLETEMPLATE_H
#define ABSTRACTTRANSLATABLETEMPLATE_H

#include "AbstractTemplatePage.h"
#include "page/model/AbstractTranslatableModel.h"

namespace web
{
namespace page
{
namespace templates
{

class AbstractTranslatableTemplatePrivate;

class WEBFRAMEWORKQTSHARED_EXPORT AbstractTranslatableTemplate : public AbstractTemplatePage
{
    public:
        virtual void setRequest(Tufao::HttpServerRequest *r) Q_DECL_OVERRIDE;

    protected:
        AbstractTranslatableTemplate(AbstractTranslatableTemplatePrivate *d);
        model::AbstractTranslatableModel *initTranslatableModel(model::AbstractTranslatableModel *model);

    private:
        Q_DECLARE_PRIVATE(AbstractTranslatableTemplate)
};

}
}
}

#endif // ABSTRACTTRANSLATABLETEMPLATE_H
