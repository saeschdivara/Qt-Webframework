#include "JsCode.h"
#include <QtCore/QByteArray>

namespace web
{
namespace page
{

class JsCodePrivate
{
    public:
        QString code;
};

JsCode::JsCode(QString code) :
    d(new JsCodePrivate)
{
    d->code = code;
}

QByteArray JsCode::code() const
{
    return d->code.toUtf8();
}

}
}
