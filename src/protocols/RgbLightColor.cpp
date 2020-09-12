#include <protocols/RgbLightColor.hpp>
#include <utils/EnumMapper.hpp>

namespace Lego
{

QMap<QString, RgbLightColor> rgbLightColorIdentifierMapping = {
    { "UNKNOWN", RgbLightColor::UNKNOWN },
    { "AMBER", RgbLightColor::AMBER },
    { "BLUE", RgbLightColor::BLUE },
    { "CYAN", RgbLightColor::CYAN },
    { "GREEN", RgbLightColor::GREEN },
    { "OFF", RgbLightColor::OFF },
    { "PINK", RgbLightColor::PINK },
    { "PURPLE", RgbLightColor::PURPLE },
    { "RED", RgbLightColor::RED },
    { "TURQUOISE", RgbLightColor::TURQUOISE },
    { "YELLOW", RgbLightColor::YELLOW },
    { "WHITE", RgbLightColor::WHITE },
};

QString rgbLightColorToIdentifier(RgbLightColor value)
{
    return enumToIdentifierWithDefault(rgbLightColorIdentifierMapping, value, "UNKNOWN");
}

RgbLightColor rgbLightColorFromIdentifier(const QString& identifier)
{
    return enumFromIdentifierWithDefault(rgbLightColorIdentifierMapping, identifier, RgbLightColor::UNKNOWN);
}

RgbLightColors getRgbLightColors(void)
{
    return RgbLightColors({
        RgbLightColor::AMBER,
        RgbLightColor::BLUE,
        RgbLightColor::CYAN,
        RgbLightColor::GREEN,
        RgbLightColor::OFF,
        RgbLightColor::PINK,
        RgbLightColor::PURPLE,
        RgbLightColor::RED,
        RgbLightColor::TURQUOISE,
        RgbLightColor::YELLOW,
        RgbLightColor::WHITE,
    });
}

} /* namespace Lego */
