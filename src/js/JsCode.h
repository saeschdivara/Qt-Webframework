#ifndef JSCODE_H
#define JSCODE_H

#include "webframework-qt_global.h"

namespace web
{
namespace page
{

class JsCodePrivate;

class WEBFRAMEWORKQTSHARED_EXPORT JsCode
{
    public:
        JsCode(QString code);
        inline QByteArray code() const;

    private:
        JsCodePrivate *d;
};

}
}

#endif // JSCODE_H
