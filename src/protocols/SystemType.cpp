#include <protocols/SystemType.hpp>
#include <utils/EnumMapper.hpp>

namespace Lego
{

QMap<QString, SystemType> systemTypeIdentifierMapping = {
    { "UNKNOWN", SystemType::UNKNOWN },
    { "MARIO", SystemType::MARIO },
    { "MOVE_HUB", SystemType::MOVE_HUB },
    { "TECHNIC_HUB", SystemType::TECHNIC_HUB },
};

QString systemTypeToIdentifier(SystemType value)
{
    return enumToIdentifierWithDefault(systemTypeIdentifierMapping, value, "UNKNOWN");
}

SystemType systemTypeFromIdentifier(const QString& identifier)
{
    return enumFromIdentifierWithDefault(systemTypeIdentifierMapping, identifier, SystemType::UNKNOWN);
}

} /* namespace Lego */
