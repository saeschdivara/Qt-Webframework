#ifndef PAGEINTERFACE_H
#define PAGEINTERFACE_H

#include "webframework-qt_global.h"
#include <QtCore/QByteArray>

namespace web
{
namespace page
{

class WEBFRAMEWORKQTSHARED_EXPORT PageInterface
{
    public:
        virtual ~PageInterface() {}

        virtual QByteArray getContent() = 0;
};

}
}

#endif // PAGEINTERFACE_H
