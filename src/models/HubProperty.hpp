#ifndef MODELS_HUBPROPERTY_HPP_
#define MODELS_HUBPROPERTY_HPP_

#include <QtCore/QTextStream>

namespace Lego
{

enum class HubProperty
{
    UNKNOWN = -1,
    ADVERTISED_NAME = 0x01,
    BUTTON = 0x02,
    BATTERY_LEVEL = 0x06,
    SYSTEM_TYPE_ID = 0x0b,
};

QTextStream& operator<<(QTextStream& stream, HubProperty value);

} /* namespace Lego */

#endif /* MODELS_HUBPROPERTY_HPP_ */
