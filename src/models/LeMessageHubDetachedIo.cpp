#include <models/LeMessageHubDetachedIo.hpp>

namespace Lego
{

LeMessageHubDetachedIo::LeMessageHubDetachedIo()
{
}

void LeMessageHubDetachedIo::dump(QTextStream& stream) const
{
    stream << "LeMessageHubDetachedIo[";
    stream << "port=" << port;
    stream << "]";
}

} /* namespace Lego */
