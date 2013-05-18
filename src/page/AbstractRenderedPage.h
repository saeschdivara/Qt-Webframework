#ifndef ABSTRACTRENDEREDPAGE_H
#define ABSTRACTRENDEREDPAGE_H

#include "webframework-qt_global.h"
#include "StatefulPageInterface.h"

namespace web
{
namespace page
{

class AbstractRenderedPagePrivate;

class WEBFRAMEWORKQTSHARED_EXPORT AbstractRenderedPage : public  StatefulPageInterface
{
    public:
        virtual void getContent();

    protected:
        AbstractRenderedPagePrivate *d_ptr;
        AbstractRenderedPage(AbstractRenderedPagePrivate *d);

        virtual void render() = 0;

    private:
        Q_DECLARE_PRIVATE(AbstractRenderedPage)
};

}
}

#endif // ABSTRACTRENDEREDPAGE_H
