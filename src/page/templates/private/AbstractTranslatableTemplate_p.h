#ifndef ABSTRACTTRANSLATABLETEMPLATE_P_H
#define ABSTRACTTRANSLATABLETEMPLATE_P_H

#include "AbstractTemplatePage_p.h"

namespace web
{
namespace page
{
namespace templates
{

class AbstractTranslatableTemplatePrivate : public AbstractTemplatePagePrivate
{
    public:
        QString clientLanguage;
};

}
}
}

#endif // ABSTRACTTRANSLATABLETEMPLATE_P_H
