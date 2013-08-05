#include "TemplateTag.h"

namespace web
{
namespace page
{
namespace templates
{
namespace tags
{

QString &TemplateTag::tag() const
{
    return QStringLiteral("tpl");
}

void TemplateTag::setAttributes(QDomNamedNodeMap attributes)
{
    //
}

void TemplateTag::render()
{
    //
}

QByteArray TemplateTag::getRenderedContent()
{
    //
}

}
}
}
}
