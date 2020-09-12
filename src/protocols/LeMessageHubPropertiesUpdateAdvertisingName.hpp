#ifndef PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATEADVERTISINGNAME_HPP_
#define PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATEADVERTISINGNAME_HPP_

#include <QtCore/QByteArray>
#include <models/GenericLeMessage.hpp>
#include <models/HubProperty.hpp>
#include <models/HubPropertyOperation.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubPropertiesUpdateAdvertisingName(
    HubProperty property,
    HubPropertyOperation operation,
    const QByteArray& data);

} /* namespace Lego */

#endif /* PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATEADVERTISINGNAME_HPP_ */
