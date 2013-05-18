#ifndef ABSTRACTRENDEREDPAGE_P_H
#define ABSTRACTRENDEREDPAGE_P_H

#include <QtCore/QByteArray>
#include <sessionstore.h>

namespace web {
namespace page {

class AbstractRenderedPagePrivate
{
    public:
        QByteArray data;
        Tufao::SessionStore *session;
};

}
}

#endif // ABSTRACTRENDEREDPAGE_P_H
