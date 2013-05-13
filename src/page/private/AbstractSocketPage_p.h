#ifndef ABSTRACTSOCKETPAGE_P_H
#define ABSTRACTSOCKETPAGE_P_H

#include <websocket.h>

namespace web
{
namespace page
{

class AbstractSocketPagePrivate
{
    public:
        Tufao::WebSocket *websocket;
};

}
}

#endif // ABSTRACTSOCKETPAGE_P_H
