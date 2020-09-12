#include <protocols/HubProperty.hpp>

namespace Lego
{

QTextStream& operator<<(QTextStream& stream, HubProperty value)
{
    stream << hubPropertyToIdentifier(value);

    return stream;
}

} /* namespace Lego */
