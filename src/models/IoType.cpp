#include <protocols/IoType.hpp>

namespace Lego
{

QTextStream& operator<<(QTextStream& stream, IoType value)
{
    stream << ioTypeToIdentifier(value);

    return stream;
}

} /* namespace Lego */
