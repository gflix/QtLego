#include <protocols/HubProperty.hpp>
#include <utils/EnumMapper.hpp>

namespace Lego
{

QMap<QString, HubProperty> hubPropertyIdentifierMapping = {
    { "UNKNOWN", HubProperty::UNKNOWN },
    { "ADVERTISED_NAME", HubProperty::ADVERTISED_NAME },
    { "BATTERY_LEVEL", HubProperty::BATTERY_LEVEL },
    { "BUTTON", HubProperty::BUTTON },
    { "SYSTEM_TYPE_ID", HubProperty::SYSTEM_TYPE_ID },
};

QString hubPropertyToIdentifier(HubProperty value)
{
    return enumToIdentifierWithDefault(hubPropertyIdentifierMapping, value, "UNKNOWN");
}

HubProperty hubPropertyFromIdentifier(const QString& identifier)
{
    return enumFromIdentifierWithDefault(hubPropertyIdentifierMapping, identifier, HubProperty::UNKNOWN);
}

} /* namespace Lego */
