#ifndef ABSTRACTHTMLELEMENT_H
#define ABSTRACTHTMLELEMENT_H

#include "webframework-qt_global.h"
#include <QtCore/QByteArray>

namespace web {
namespace htmlelement {

class WEBFRAMEWORKQTSHARED_EXPORT AbstractHtmlElement
{
    public:
        QByteArray toHtml();
};

}
}


#endif // ABSTRACTHTMLELEMENT_H
