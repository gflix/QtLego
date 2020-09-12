#include <models/LeMessageHubPropertiesUpdateAdvertisingName.hpp>
#include <protocols/LeMessageHubPropertiesUpdateAdvertisingName.hpp>
#include <utils/Converter.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubPropertiesUpdateAdvertisingName(
    HubProperty property,
    HubPropertyOperation operation,
    const QByteArray& data)
{
    auto message = new LeMessageHubPropertiesUpdateAdvertisingName();
    LeMessage leMessage { message };

    message->property = property;
    message->operation = operation;
    message->advertisingName = Converter::byteArrayToString(data).trimmed();

    return leMessage;
}

} /* namespace Lego */
