#include <models/LeMessageHubPropertiesUpdateBatteryLevel.hpp>
#include <protocols/LeMessageHubPropertiesUpdateBatteryLevel.hpp>
#include <utils/Converter.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubPropertiesUpdateBatteryLevel(int property, int operation, const QByteArray& data)
{
    auto dataSize = data.size();
    if (dataSize < 1)
    {
        throw std::invalid_argument("expect at least 1 bytes for decoding HubPropertiesUpdateBatteryLevel message");
    }

    auto message = new LeMessageHubPropertiesUpdateBatteryLevel();
    LeMessage leMessage { message };

    message->property = property;
    message->operation = operation;
    message->batteryLevel = Converter::byteArrayToUnsignedChar(data.mid(0, 1));

    return leMessage;
}

} /* namespace Lego */
