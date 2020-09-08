#include <models/LeMessageHubAttachedIo.hpp>
#include <protocols/LeMessageHubAttachedIo.hpp>
#include <utils/Converter.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubAttachedIo(int port, const QByteArray& data)
{
    auto dataSize = data.size();
    if (dataSize < 2)
    {
        throw std::invalid_argument("expect at least 2 bytes for decoding HubAttachedIo message");
    }

    auto message = new LeMessageHubAttachedIo();
    LeMessage leMessage { message };

    message->port = port;
    message->ioType = Converter::byteArrayToUnsignedShortLe(data.mid(0, 2));

    return leMessage;
}

} /* namespace Lego */
