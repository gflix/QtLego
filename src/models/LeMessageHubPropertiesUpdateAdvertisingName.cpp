#include <models/LeMessageHubPropertiesUpdateAdvertisingName.hpp>

namespace Lego
{

LeMessageHubPropertiesUpdateAdvertisingName::LeMessageHubPropertiesUpdateAdvertisingName()
{
}

void LeMessageHubPropertiesUpdateAdvertisingName::dump(QTextStream& stream) const
{
    stream << "LeMessageHubPropertiesUpdateAdvertisingName[";
    stream << "property=" << property << ",";
    stream << "operation=" << operation << ",";
    stream << "advertisingName=" << advertisingName;
    stream << "]";
}

} /* namespace Lego */
