#ifndef PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATEBATTERYLEVEL_HPP_
#define PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATEBATTERYLEVEL_HPP_

#include <QtCore/QByteArray>
#include <models/GenericLeMessage.hpp>
#include <models/HubProperty.hpp>
#include <models/HubPropertyOperation.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubPropertiesUpdateBatteryLevel(
    HubProperty property,
    HubPropertyOperation operation,
    const QByteArray& data);

} /* namespace Lego */

#endif /* PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATEBATTERYLEVEL_HPP_ */
