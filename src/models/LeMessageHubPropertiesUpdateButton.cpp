#include <models/LeMessageHubPropertiesUpdateButton.hpp>

namespace Lego
{

LeMessageHubPropertiesUpdateButton::LeMessageHubPropertiesUpdateButton()
{
}

void LeMessageHubPropertiesUpdateButton::dump(QTextStream& stream) const
{
    stream << "LeMessageHubPropertiesUpdateButton[";
    stream << "property=" << property << ",";
    stream << "operation=" << operation << ",";
    stream << "pressed=" << pressed;
    stream << "]";
}

} /* namespace Lego */
