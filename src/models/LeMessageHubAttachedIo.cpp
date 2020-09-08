#include <models/LeMessageHubAttachedIo.hpp>

namespace Lego
{

LeMessageHubAttachedIo::LeMessageHubAttachedIo():
    ioType(0)
{
}

void LeMessageHubAttachedIo::dump(QTextStream& stream) const
{
    stream << "LeMessageHubAttachedIo[";
    stream << "port=" << port << ",";
    stream << "ioType=" << ioType;
    stream << "]";
}

} /* namespace Lego */
