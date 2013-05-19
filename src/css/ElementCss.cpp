#include "ElementCss.h"

namespace web
{
namespace css
{

class ElementCssPrivate
{
    public:
};

ElementCss::ElementCss() :
    ElementCss(new ElementCssPrivate)
{
}

QByteArray ElementCss::data()
{
    return QByteArray();
}

ElementCss::ElementCss(ElementCssPrivate *d) :
    d_ptr(d)
{
}

}
}
