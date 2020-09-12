#include <models/LeMessageHubPropertiesUpdateSystemType.hpp>

namespace Lego
{

LeMessageHubPropertiesUpdateSystemType::LeMessageHubPropertiesUpdateSystemType()
{
}

void LeMessageHubPropertiesUpdateSystemType::dump(QTextStream& stream) const
{
    stream << "LeMessageHubPropertiesUpdateSystemType[";
    stream << "property=" << property << ",";
    stream << "operation=" << operation << ",";
    stream << "systemType=" << systemType;
    stream << "]";
}

} /* namespace Lego */
