#include <protocols/GenericLeMessageHubAttachedIo.hpp>
#include <protocols/LeMessageHubAttachedIo.hpp>
#include <protocols/LeMessageHubDetachedIo.hpp>
#include <utils/Converter.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubAttachedIo(const QByteArray& data)
{
    auto dataSize = data.size();
    if (dataSize < 2)
    {
        throw std::invalid_argument("expect at least 2 bytes for decoding HubAttachedIo message");
    }

    auto payload = data.mid(2);
    int port = Converter::byteArrayToUnsignedChar(data.mid(0, 1));
    int event = Converter::byteArrayToUnsignedChar(data.mid(1, 1));

    switch (event)
    {
        case 0:
            return decodeLeMessageHubDetachedIo(port, payload);
        case 1:
            return decodeLeMessageHubAttachedIo(port, payload);
        default:
            break;
    }

    throw std::domain_error("invalid hub attachement i/o event");
}

} /* namespace Lego */
