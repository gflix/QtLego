#include <models/LeMessageHubAttachedIo.hpp>

namespace Lego
{

LeMessageHubAttachedIo::LeMessageHubAttachedIo():
    ioType(IoType::UNKNOWN)
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
