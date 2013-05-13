#ifndef ABSTRACTSOCKETPAGE_H
#define ABSTRACTSOCKETPAGE_H

#include "webframework-qt_global.h"
#include "StatefulPageInterface.h"

namespace web
{
namespace page
{

class AbstractSocketPagePrivate;

class WEBFRAMEWORKQTSHARED_EXPORT AbstractSocketPage : public StatefulPageInterface
{
    public:
        AbstractSocketPage();

        virtual void injectJavaScript() = 0;

    protected:
        AbstractSocketPage(AbstractSocketPagePrivate *pr);
        AbstractSocketPagePrivate *d_ptr;

    private:
        Q_DECLARE_PRIVATE(AbstractSocketPage)
};

}
}

#endif // ABSTRACTSOCKETPAGE_H
