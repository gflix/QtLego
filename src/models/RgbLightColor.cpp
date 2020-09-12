#include <protocols/RgbLightColor.hpp>

namespace Lego
{

QTextStream& operator<<(QTextStream& stream, RgbLightColor value)
{
    stream << rgbLightColorToIdentifier(value);

    return stream;
}

} /* namespace Lego */
