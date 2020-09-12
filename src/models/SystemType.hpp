#ifndef MODELS_SYSTEMTYPE_HPP_
#define MODELS_SYSTEMTYPE_HPP_

#include <QtCore/QTextStream>

namespace Lego
{

enum class SystemType
{
    UNKNOWN = -1,
    MARIO = 0x02,
    MOVE_HUB = 0x40,
    TECHNIC_HUB = 0x80,
};

QTextStream& operator<<(QTextStream& stream, SystemType value);

} /* namespace Lego */

#endif /* MODELS_SYSTEMTYPE_HPP_ */
