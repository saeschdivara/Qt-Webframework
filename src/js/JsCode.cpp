#include "JsCode.h"
#include <QtCore/QByteArray>

namespace web
{
namespace page
{

class JsCodePrivate
{
    public:
        QByteArray code;
};

JsCode::JsCode() :
    d(new JsCodePrivate)
{
}

QByteArray &JsCode::code() const
{
    return d->code;
}

}
}
