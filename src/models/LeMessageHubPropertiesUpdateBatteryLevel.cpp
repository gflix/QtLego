#include <models/LeMessageHubPropertiesUpdateBatteryLevel.hpp>

namespace Lego
{

LeMessageHubPropertiesUpdateBatteryLevel::LeMessageHubPropertiesUpdateBatteryLevel():
    batteryLevel(0)
{
}

void LeMessageHubPropertiesUpdateBatteryLevel::dump(QTextStream& stream) const
{
    stream << "LeMessageHubPropertiesUpdateBatteryLevel[";
    stream << "property=" << property << ",";
    stream << "operation=" << operation << ",";
    stream << "batteryLevel=" << batteryLevel;
    stream << "]";
}

} /* namespace Lego */
