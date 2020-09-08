#include <protocols/IoType.hpp>
#include <utils/EnumMapper.hpp>

namespace Lego
{

QMap<QString, IoType> ioTypeIdentifierMapping = {
    { "UNKNOWN", IoType::UNKNOWN },
    { "COLOR_DISTANCE_SENSOR", IoType::COLOR_DISTANCE_SENSOR },
    { "CURRENT", IoType::CURRENT },
    { "M_MOTOR", IoType::M_MOTOR },
    { "RGB_LIGHT", IoType::RGB_LIGHT },
    { "TECHNIC_L_MOTOR", IoType::TECHNIC_L_MOTOR },
    { "TECHNIC_XL_MOTOR", IoType::TECHNIC_XL_MOTOR },
    { "VOLTAGE", IoType::VOLTAGE },
};

QString ioTypeToIdentifier(IoType value)
{
    return enumToIdentifierWithDefault(ioTypeIdentifierMapping, value, "UNKNOWN");
}

IoType ioTypeFromIdentifier(const QString& identifier)
{
    return enumFromIdentifierWithDefault(ioTypeIdentifierMapping, identifier, IoType::UNKNOWN);
}

} /* namespace Lego */
