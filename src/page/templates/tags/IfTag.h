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

        /**
         * @brief Returns the tag name if
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual QString tag() const Q_DECL_OVERRIDE;

        /**
         * @brief This method is here to save the dom element
         * and its attributes which can be the following:
         * property (required)
         * equals / not-equals
         *
         * @param element
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void setElement(QDomElement element) Q_DECL_OVERRIDE;

        /**
         * @brief This method is to save the content between
         * the tags like <b>content</b>. The content can include
         * html tags
         *
         * @param content
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void setTagContent(const QByteArray & content) Q_DECL_OVERRIDE;

        /**
         * @brief This is the model which holds the property
         *
         * @param pageModel
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void setPageModel(model::AbstractModel * pageModel) Q_DECL_OVERRIDE;

        /**
         * @brief This method is not used
         *
         * @param templateModels
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void setModelList(QHash<QString, model::AbstractListModel *> templateModels) Q_DECL_OVERRIDE;

        /**
         * @brief This method is not used
         *
         * @param templates
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void setTemplateList(QHash<QString, QByteArray> templates) Q_DECL_OVERRIDE;

        /**
         * @brief Returns true if the property is equals or not equals
         * the string in the attribute
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual bool isContentAllowed() Q_DECL_OVERRIDE;

        /**
         * @brief Renderes what the content shall be in the
         * page content after the attributes and the content
         * are set
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
        virtual void render() Q_DECL_OVERRIDE;

        /**
         * @brief This method should return the rendered tag content
         * with its start and end tag
         *
         * @return
         *
         * @author Sascha Häusler <saeschdivara@gmail.com>
         * @since 0.3
         */
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
