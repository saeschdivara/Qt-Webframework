#ifndef ABSTRACTWEBSITE_P_H
#define ABSTRACTWEBSITE_P_H

#include <QtCore/QList>
#include <QtCore/QUrl>
#include "page/PageInterface.h"

namespace web {
namespace website {

class AbstractWebsitePrivate
{
public:
        QUrl url;
        QList<page::PageInterface *> pages;
};

}
}

#endif // ABSTRACTWEBSITE_P_H
