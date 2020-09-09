#ifndef PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATEBATTERYLEVEL_HPP_
#define PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATEBATTERYLEVEL_HPP_

#include <QtCore/QByteArray>
#include <models/GenericLeMessage.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubPropertiesUpdateBatteryLevel(int property, int operation, const QByteArray& data);

} /* namespace Lego */

#endif /* PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATEBATTERYLEVEL_HPP_ */
