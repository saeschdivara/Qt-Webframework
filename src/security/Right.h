#ifndef RIGHT_H
#define RIGHT_H

#include <QtCore/QtGlobal>

namespace web {
namespace security {

enum class Right : quint16 {
    NoRight = 0x0,
    ReadRight =  0x1,
    WriteRight = 0x2,
    ReadWriteRight = ReadRight | WriteRight
};

}
}

#endif // RIGHT_H
