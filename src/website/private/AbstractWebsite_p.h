#ifndef ABSTRACTWEBSITE_P_H
#define ABSTRACTWEBSITE_P_H

#include <QtCore/QHash>
#include <QtCore/QUrl>
#include <QtCore/QScopedPointer>
#include <httpserver.h>
#include <simplesessionstore.h>
#include "page/PageInterface.h"

namespace web {
namespace website {

class AbstractWebsitePrivate
{
public:
        QUrl url;
        QHash<QString ,page::PageInterface *> pages;
        QScopedPointer<Tufao::HttpServer> server;
        Tufao::SimpleSessionStore sessionStore;
};

}
}

#endif // ABSTRACTWEBSITE_P_H
