/********************************************************************************
 ** The MIT License (MIT)
 **
 ** Copyright (c) 2013 Sascha Ludwig Häusler
 **
 ** Permission is hereby granted, free of charge, to any person obtaining a copy of
 ** this software and associated documentation files (the "Software"), to deal in
 ** the Software without restriction, including without limitation the rights to
 ** use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 ** the Software, and to permit persons to whom the Software is furnished to do so,
 ** subject to the following conditions:
 **
 ** The above copyright notice and this permission notice shall be included in all
 ** copies or substantial portions of the Software.
 **
 ** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 ** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 ** FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 ** COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 ** IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 ** CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *********************************************************************************/

#include "IfTag.h"
#include "private/TagInterfacePrivate.h"

#include "util/TemplateRenderHelper.h"

namespace web
{
namespace page
{
namespace templates
{
namespace tags
{

class IfTagPrivate : public TagInterfacePrivate
{
    public:
};

IfTag::IfTag() :
    d_ptr(new IfTagPrivate)
{
    Q_D(IfTag);
    d->tagName = "if";
    d->isContentAllowed = false;
}


QString IfTag::tag() const
{
    Q_D(const IfTag);
    return d->tagName;
}

void IfTag::setElement(QDomElement element)
{
    Q_D(IfTag);
    d->element = element;
}

void IfTag::setTagContent(const QByteArray & content)
{
    Q_D(IfTag);
    d->content = content;
}

void IfTag::setPageModel(web::page::model::AbstractModel * pageModel)
{
    Q_D(IfTag);
    d->pageModel = pageModel;
}

void IfTag::setModelList(QHash<QString, web::page::model::AbstractListModel *> templateModels)
{
    Q_UNUSED(templateModels);
}

void IfTag::setTemplateList(QHash<QString, QByteArray> templates)
{
    Q_UNUSED(templates);
}

bool IfTag::isContentAllowed()
{
    Q_D(IfTag);
    return d->isContentAllowed;
}

void IfTag::render()
{
    Q_D(IfTag);

    if ( !d->element.hasAttribute(QLatin1String("property")) ) return;

    QString prop = d->pageModel->property(d->element.attribute("property").toLocal8Bit()).toString();

    if ( d->element.hasAttribute(QLatin1String("equals")) ) {
        QString attr = d->element.attribute(QLatin1String("equals"));
        if ( prop == attr )
            d->isContentAllowed = true;
    }
    else if ( d->element.hasAttribute(QLatin1String("not-equals")) ) {
        QString attr = d->element.attribute(QLatin1String("not-equals"));
        if ( prop != attr )
            d->isContentAllowed = true;
    }

    if ( d->isContentAllowed ) {
        QString templateOutput = d->content;
        util::TemplateRenderHelper::replaceModelPlaceholders(templateOutput, d->pageModel);
        d->content = templateOutput.toUtf8();
    }
}

QByteArray IfTag::getRenderedContent()
{
    Q_D(IfTag);
    return d->content;
}

}
}
}
}
