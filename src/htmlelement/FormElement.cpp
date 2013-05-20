#include "FormElement.h"
#include "private/AbstractHtmlElement_p.h"

namespace web {
namespace htmlelement {

class FormElementPrivate : public AbstractHtmlElementPrivate
{
    public:
};

FormElement::FormElement() :
    AbstractHtmlElement(new FormElementPrivate)
{
    Q_D(FormElement);
    d->tag = QByteArray("form");
}

InputElement *FormElement::appendTextInput(InputElement *input)
{
    append(input);
    input->addAttribute("type", "text");

    return input;
}

InputElement *FormElement::appendPasswordInput(InputElement *input)
{
    append(input);
    input->addAttribute("type", "password");

    return input;
}

InputElement *FormElement::appendSubmit(InputElement *submit)
{
    append(submit);
    submit->addAttribute("type", "submit");
    submit->addAttribute("value", "Submit");

    return submit;
}

TextElement *FormElement::appendText(QByteArray text)
{
    TextElement* t = new TextElement(text);
    append(t);
    return t;
}

}
}
