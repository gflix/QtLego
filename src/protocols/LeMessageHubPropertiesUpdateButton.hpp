#ifndef PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATEBUTTON_HPP_
#define PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATEBUTTON_HPP_

#include <QtCore/QByteArray>
#include <models/GenericLeMessageHubProperties.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubPropertiesUpdateButton(
    HubProperty property,
    HubPropertyOperation operation,
    const QByteArray& data);

} /* namespace Lego */

#endif /* PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATEBUTTON_HPP_ */
