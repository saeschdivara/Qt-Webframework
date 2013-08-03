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

/**
 * @brief This class offers only the possibilty that through the request
 * the language is set and that a method to get the translated text back.
 *
 * @author Sascha Häusler <saeschdivara@gmail.com>
 * @since 0.2
 */
class WEBFRAMEWORKQTSHARED_EXPORT AbstractTranslatableTemplate : public AbstractTemplatePage
{
    public:
        /**
         * @brief Besides storing the pointer to the request, it analyses
         * the request to be able to set the language for the page.
         *
         * @param r Pointer to the request
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        virtual void setRequest(Tufao::HttpServerRequest *r) Q_DECL_OVERRIDE;

    protected:
        AbstractTranslatableTemplate(AbstractTranslatableTemplatePrivate *d);

        /**
         * @brief Sets the language for the AbstractTranslatableModel
         *
         * @param model Model which needs the language to be set
         *
         * @return Returns the same model again
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.2
         */
        model::AbstractModel *setLanguageForModel(model::AbstractModel *model);

    private:
        Q_DECLARE_PRIVATE(AbstractTranslatableTemplate)
};

}
}
}

#endif // ABSTRACTTRANSLATABLETEMPLATE_H
