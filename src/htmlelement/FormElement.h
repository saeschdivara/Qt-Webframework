#ifndef FORMELEMENT_H
#define FORMELEMENT_H

#include "webframework-qt_global.h"
#include "AbstractHtmlElement.h"
#include "InputElement.h"
#include "TextElement.h"

namespace web {
namespace htmlelement {

class FormElementPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT FormElement : public AbstractHtmlElement
{
    public:
        FormElement();

        InputElement* appendTextInput(InputElement* input = new InputElement);
        InputElement* appendPasswordInput(InputElement* input = new InputElement);
        InputElement* appendSubmit(InputElement* submit = new InputElement);
        TextElement* appendText(QByteArray text);

    private:
        Q_DECLARE_PRIVATE(FormElement)
};

}
}

#endif // FORMELEMENT_H
