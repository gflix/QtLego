#ifndef PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATESYSTEMTYPE_HPP_
#define PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATESYSTEMTYPE_HPP_

#include <QtCore/QByteArray>
#include <models/GenericLeMessageHubProperties.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubPropertiesUpdateSystemType(
    HubProperty property,
    HubPropertyOperation operation,
    const QByteArray& data);

} /* namespace Lego */

#endif /* PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATESYSTEMTYPE_HPP_ */
