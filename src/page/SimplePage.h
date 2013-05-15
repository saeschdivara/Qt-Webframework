#ifndef SIMPLEPAGE_H
#define SIMPLEPAGE_H

#include "webframework-qt_global.h"
#include "PageInterface.h"

namespace web
{
namespace page
{

class SimplePagePrivate;

class WEBFRAMEWORKQTSHARED_EXPORT SimplePage : public PageInterface
{
    public:
        SimplePage(QString fileName);
        ~SimplePage();

        virtual QByteArray getContent() const Q_DECL_OVERRIDE;

    protected:
        SimplePage(SimplePagePrivate *pr, QString fileName);
        SimplePagePrivate *d_ptr;

    private:
        Q_DECLARE_PRIVATE(SimplePage)
};

}
}

#endif // SIMPLEPAGE_H
