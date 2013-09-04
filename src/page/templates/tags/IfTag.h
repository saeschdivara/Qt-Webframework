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

#ifndef IFTAG_H
#define IFTAG_H

#include "TagInterface.h"

namespace web
{
namespace page
{
namespace templates
{
namespace tags
{

class IfTagPrivate;

/**
 * @brief The IfTag class
 *
 * @author Sascha Häusler <saeschdivara@gmail.com>
 * @since 0.3
 */
class WEBFRAMEWORKQTSHARED_EXPORT IfTag : public TagInterface
{
    public:
        IfTag();

        virtual QString tag() const Q_DECL_OVERRIDE;
        virtual void setElement(QDomElement element) Q_DECL_OVERRIDE;
        virtual void setTagContent(const QByteArray & content) Q_DECL_OVERRIDE;
        virtual void setPageModel(model::AbstractModel * pageModel) Q_DECL_OVERRIDE;
        virtual void setModelList(QHash<QString, model::AbstractListModel *> templateModels) Q_DECL_OVERRIDE;
        virtual void setTemplateList(QHash<QString, QByteArray> templates) Q_DECL_OVERRIDE;
        virtual void setTemplateRenderer(TagRenderer * renderer) Q_DECL_OVERRIDE;
        virtual bool isContentAllowed() Q_DECL_OVERRIDE;
        virtual void render() Q_DECL_OVERRIDE;
        virtual QByteArray getRenderedContent() Q_DECL_OVERRIDE;

    protected:
        IfTagPrivate * d_ptr;

    private:
        Q_DECLARE_PRIVATE(IfTag)
};

}
}
}
}

#endif // IFTAG_H
