#include <models/LeMessageHubAttachedIo.hpp>
#include <protocols/LeMessageHubAttachedIo.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubAttachedIo(int port, const QByteArray& data)
{
    auto message = new LeMessageHubAttachedIo();
    LeMessage leMessage { message };

    message->port = port;

    return leMessage;
}

} /* namespace Lego */
