#include <protocols/HubPropertyOperation.hpp>
#include <utils/EnumMapper.hpp>

namespace Lego
{

QMap<QString, HubPropertyOperation> hubPropertyOperationIdentifierMapping = {
    { "UNKNOWN", HubPropertyOperation::UNKNOWN },
    { "ENABLE_UPDATES", HubPropertyOperation::ENABLE_UPDATES },
    { "REQUEST_UPDATE", HubPropertyOperation::REQUEST_UPDATE },
    { "UPDATE", HubPropertyOperation::UPDATE },
};

QString hubPropertyOperationToIdentifier(HubPropertyOperation value)
{
    return enumToIdentifierWithDefault(hubPropertyOperationIdentifierMapping, value, "UNKNOWN");
}

HubPropertyOperation hubPropertyFromIdentifier(const QString& identifier)
{
    return enumFromIdentifierWithDefault(
        hubPropertyOperationIdentifierMapping,
        identifier,
        HubPropertyOperation::UNKNOWN);
}

} /* namespace Lego */
