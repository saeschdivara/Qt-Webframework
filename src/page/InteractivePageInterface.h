#ifndef INTERACTIVEPAGEINTERFACE_H
#define INTERACTIVEPAGEINTERFACE_H

#include "webframework-qt_global.h"
#include "StatefulPageInterface.h"

namespace web
{
namespace page
{

class WEBFRAMEWORKQTSHARED_EXPORT InteractivePageInterface : public StatefulPageInterface
{
    public:
        virtual ~InteractivePageInterface() {}
};

}
}

#endif // INTERACTIVEPAGEINTERFACE_H
