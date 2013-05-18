#include "AbstractRenderedPage.h"
#include "private/AbstractRenderedPage_p.h"

namespace web {
namespace page {

QByteArray AbstractRenderedPage::getContent()
{
    Q_D(AbstractRenderedPage);

    render();
    return d->data;
}

void AbstractRenderedPage::setSession(Tufao::SessionStore *s)
{
    Q_D(AbstractRenderedPage);
    d->session = s;
}

AbstractRenderedPage::AbstractRenderedPage(AbstractRenderedPagePrivate *d) :
    d_ptr(d)
{
}

}

}
