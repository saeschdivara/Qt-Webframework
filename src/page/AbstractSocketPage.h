#ifndef ABSTRACTSOCKETPAGE_H
#define ABSTRACTSOCKETPAGE_H

#include "webframework-qt_global.h"
#include "page/StatefulPageInterface.h"
#include "js/JsCode.h"

namespace web
{
namespace page
{

class AbstractSocketPagePrivate;

class WEBFRAMEWORKQTSHARED_EXPORT AbstractSocketPage : public StatefulPageInterface
{
    public:
        AbstractSocketPage();

        virtual void injectJavaScript(js::JsCode &code) = 0;

    protected:
        AbstractSocketPage(AbstractSocketPagePrivate *pr);
        AbstractSocketPagePrivate *d_ptr;

    private:
        Q_DECLARE_PRIVATE(AbstractSocketPage)
};

}
}

#endif // ABSTRACTSOCKETPAGE_H
