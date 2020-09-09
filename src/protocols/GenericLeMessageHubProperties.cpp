#include <protocols/GenericLeMessageHubProperties.hpp>
#include <protocols/LeMessageHubPropertiesUpdateBatteryLevel.hpp>
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
    int property = Converter::byteArrayToUnsignedChar(data.mid(0, 1));
    int operation = Converter::byteArrayToUnsignedChar(data.mid(1, 1));

    if (property == 6 && operation == 6)
    {
        return decodeLeMessageHubPropertiesUpdateBatteryLevel(property, operation, payload);
    }

    throw std::domain_error("unsupported hub properties messages");
}

} /* namespace Lego */
