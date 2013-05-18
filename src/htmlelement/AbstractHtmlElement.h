#ifndef ABSTRACTHTMLELEMENT_H
#define ABSTRACTHTMLELEMENT_H

#include "webframework-qt_global.h"
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QScopedPointer>

namespace web {
namespace htmlelement {

class AbstractHtmlElementPrivate;

class WEBFRAMEWORKQTSHARED_EXPORT AbstractHtmlElement
{
    public:
        virtual ~AbstractHtmlElement();

        QByteArray tag() const;

        QByteArray toHtml();
        QByteArray toJson();

        void setVisible(bool b);
        bool isVisible();

        void setReadonly(bool b);
        bool isReadonly();

        void setParent(AbstractHtmlElement *ele);

        QList<AbstractHtmlElement *> children();
        void append(AbstractHtmlElement *ele);

    protected:
        QScopedPointer<AbstractHtmlElementPrivate> d_ptr;
        AbstractHtmlElement(AbstractHtmlElementPrivate *d);

    private:
        Q_DECLARE_PRIVATE(AbstractHtmlElement)
};

}
}


#endif // ABSTRACTHTMLELEMENT_H
