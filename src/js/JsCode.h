#ifndef JSCODE_H
#define JSCODE_H

#include "webframework-qt_global.h"

namespace web
{
namespace page
{

class JsCodePrivate;

class JsCode
{
    public:
        JsCode();
        inline QByteArray& code() const;

    private:
        JsCodePrivate *d;
};

}
}

#endif // JSCODE_H
