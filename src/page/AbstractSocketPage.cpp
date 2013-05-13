#include "AbstractSocketPage.h"
#include "private/AbstractSocketPage_p.h"

namespace web
{
namespace page
{

AbstractSocketPage::AbstractSocketPage() :
    AbstractSocketPage(new AbstractSocketPagePrivate)
{
}

AbstractSocketPage::AbstractSocketPage(AbstractSocketPagePrivate *pr) :
    d_ptr(pr)
{
}

}
}
