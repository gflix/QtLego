#include <models/LeMessageHubPropertiesUpdateSystemType.hpp>
#include <protocols/LeMessageHubPropertiesUpdateSystemType.hpp>
#include <utils/Converter.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubPropertiesUpdateSystemType(
    HubProperty property,
    HubPropertyOperation operation,
    const QByteArray& data)
{
    auto dataSize = data.size();
    if (dataSize < 1)
    {
        throw std::invalid_argument("expect at least 1 bytes for decoding HubPropertiesUpdateSystemType message");
    }

    auto message = new LeMessageHubPropertiesUpdateSystemType();
    LeMessage leMessage { message };

    message->property = property;
    message->operation = operation;
    message->systemType = static_cast<SystemType>(Converter::byteArrayToUnsignedChar(data.mid(0, 1)));

    return leMessage;
}

} /* namespace Lego */
