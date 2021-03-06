#ifndef MODELS_IOTYPE_HPP_
#define MODELS_IOTYPE_HPP_

#include <QtCore/QTextStream>

namespace Lego
{

enum class IoType
{
    UNKNOWN = -1,
    VOLTAGE = 0x14,
    CURRENT = 0x15,
    RGB_LIGHT = 0x17,
    COLOR_DISTANCE_SENSOR = 0x25,
    MOTOR_W_TACHO = 0x26,
    INT_MOTOR_W_TACHO = 0x27,
    INT_TILT_SENSOR = 0x28,
    TECHNIC_L_MOTOR = 0x2e,
    TECHNIC_XL_MOTOR = 0x2f,
};

QTextStream& operator<<(QTextStream& stream, IoType value);

} /* namespace Lego */

#endif /* MODELS_IOTYPE_HPP_ */
