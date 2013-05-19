#ifndef TEXTELEMENT_H
#define TEXTELEMENT_H

#include "webframework-qt_global.h"
#include "AbstractHtmlElement.h"

namespace web {
namespace htmlelement {

class TextElementPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT TextElement : public AbstractHtmlElement
{
    public:
        TextElement(QByteArray text);

        virtual QByteArray toHtml() Q_DECL_OVERRIDE;

    private:
        Q_DECLARE_PRIVATE(TextElement)
};

}
}

#endif // TEXTELEMENT_H
