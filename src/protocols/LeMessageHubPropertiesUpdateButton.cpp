#include <models/LeMessageHubPropertiesUpdateButton.hpp>
#include <protocols/LeMessageHubPropertiesUpdateButton.hpp>
#include <utils/Converter.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubPropertiesUpdateButton(
    HubProperty property,
    HubPropertyOperation operation,
    const QByteArray& data)
{
    auto dataSize = data.size();
    if (dataSize < 1)
    {
        throw std::invalid_argument("expect at least 1 bytes for decoding HubPropertiesUpdateButton message");
    }

    auto message = new LeMessageHubPropertiesUpdateButton();
    LeMessage leMessage { message };

    message->property = property;
    message->operation = operation;
    message->pressed = Converter::byteArrayToUnsignedChar(data.mid(0, 1)) != 0;

    return leMessage;
}

} /* namespace Lego */
