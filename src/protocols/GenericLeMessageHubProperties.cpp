#include <protocols/GenericLeMessageHubProperties.hpp>
#include <protocols/LeMessageHubPropertiesUpdateAdvertisingName.hpp>
#include <protocols/LeMessageHubPropertiesUpdateBatteryLevel.hpp>
#include <protocols/LeMessageHubPropertiesUpdateButton.hpp>
#include <protocols/LeMessageHubPropertiesUpdateSystemType.hpp>
#include <utils/Converter.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubProperties(const QByteArray& data)
{
    auto dataSize = data.size();
    if (dataSize < 2)
    {
        throw std::invalid_argument("expect at least 2 bytes for decoding HubProperties message");
    }

    auto payload = data.mid(2);
    auto property = static_cast<HubProperty>(Converter::byteArrayToUnsignedChar(data.mid(0, 1)));
    auto operation = static_cast<HubPropertyOperation>(Converter::byteArrayToUnsignedChar(data.mid(1, 1)));

    if (operation == HubPropertyOperation::UPDATE)
    {
        switch (property)
        {
            case HubProperty::ADVERTISED_NAME:
                return decodeLeMessageHubPropertiesUpdateAdvertisingName(property, operation, payload);
            case HubProperty::BATTERY_LEVEL:
                return decodeLeMessageHubPropertiesUpdateBatteryLevel(property, operation, payload);
            case HubProperty::BUTTON:
                return decodeLeMessageHubPropertiesUpdateButton(property, operation, payload);
            case HubProperty::SYSTEM_TYPE_ID:
                return decodeLeMessageHubPropertiesUpdateSystemType(property, operation, payload);
        }
    }

    throw std::domain_error("unsupported hub properties messages");
}

} /* namespace Lego */
