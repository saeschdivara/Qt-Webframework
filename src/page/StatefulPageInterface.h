#ifndef STATEFULPAGEINTERFACE_H
#define STATEFULPAGEINTERFACE_H

#include "webframework-qt_global.h"
#include "PageInterface.h"
#include <sessionstore.h>

namespace web
{
namespace page
{

class WEBFRAMEWORKQTSHARED_EXPORT StatefulPageInterface : public PageInterface
{
    public:
        virtual void setSession(Tufao::SessionStore *s) = 0;
};

}
}

#endif // STATEFULPAGEINTERFACE_H
