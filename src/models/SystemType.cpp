#include <protocols/SystemType.hpp>

namespace Lego
{

QTextStream& operator<<(QTextStream& stream, SystemType value)
{
    stream << systemTypeToIdentifier(value);

    return stream;
}

} /* namespace Lego */
