#include <protocols/HubPropertyOperation.hpp>

namespace Lego
{

QTextStream& operator<<(QTextStream& stream, HubPropertyOperation value)
{
    stream << hubPropertyOperationToIdentifier(value);

    return stream;
}

} /* namespace Lego */
