#include "AbstractRenderedPage.h"
#include "private/AbstractRenderedPage_p.h"

namespace web {
namespace page {

void AbstractRenderedPage::getContent()
{
    Q_D(AbstractRenderedPage);

    render();
    return d->data;
}

AbstractRenderedPage::AbstractRenderedPage(AbstractRenderedPagePrivate *d) :
    d_ptr(d)
{
}

}

}
