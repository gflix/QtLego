#include <models/LeMessageHubDetachedIo.hpp>
#include <protocols/LeMessageHubDetachedIo.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubDetachedIo(int port, const QByteArray& data)
{
    auto message = new LeMessageHubDetachedIo();
    LeMessage leMessage { message };

    message->port = port;

    return leMessage;
}

} /* namespace Lego */
