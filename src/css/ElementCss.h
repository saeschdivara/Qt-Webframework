#ifndef ELEMENTCSS_H
#define ELEMENTCSS_H

#include "webframework-qt_global.h"
#include <QtCore/QByteArray>
#include <QtCore/QScopedPointer>

namespace web
{
namespace css
{

class ElementCssPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT ElementCss
{
    public:
        ElementCss();

        QByteArray data();

    protected:
        QScopedPointer<ElementCssPrivate> d_ptr;
        ElementCss(ElementCssPrivate *d);

    private:
        Q_DECLARE_PRIVATE(ElementCss)
};

}
}

#endif // ELEMENTCSS_H
