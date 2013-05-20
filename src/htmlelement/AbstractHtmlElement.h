#ifndef ABSTRACTHTMLELEMENT_H
#define ABSTRACTHTMLELEMENT_H

#include "webframework-qt_global.h"
#include "css/ElementCss.h"
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
        QList<AbstractHtmlElement *> findAllElementsByTag(QByteArray tag);

        virtual QByteArray toHtml();
        virtual QByteArray toJson();

        void setVisible(bool b);
        bool isVisible();

        void setReadonly(bool b);
        bool isReadonly();

        void setParent(AbstractHtmlElement *ele);

        QList<AbstractHtmlElement *>& children();
        AbstractHtmlElement* append(AbstractHtmlElement *ele);

        AbstractHtmlElement* addAttribute(QByteArray key, QByteArray value);
        AbstractHtmlElement* setID(QByteArray id);
        QByteArray ID();
        QByteArray attribute(QByteArray key);

        AbstractHtmlElement* findElementByID(QByteArray id);

        css::ElementCss* style();
        css::ElementCss* createStyle();

    protected:
        QScopedPointer<AbstractHtmlElementPrivate> d_ptr;
        AbstractHtmlElement(AbstractHtmlElementPrivate *d);

    private:
        Q_DECLARE_PRIVATE(AbstractHtmlElement)
};

}
}


#endif // ABSTRACTHTMLELEMENT_H
