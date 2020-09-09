#ifndef PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATEADVERTISINGNAME_HPP_
#define PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATEADVERTISINGNAME_HPP_

#include <QtCore/QByteArray>
#include <models/GenericLeMessage.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubPropertiesUpdateAdvertisingName(int property, int operation, const QByteArray& data);

} /* namespace Lego */

#endif /* PROTOCOLS_LEMESSAGEHUBPROPERTIESUPDATEADVERTISINGNAME_HPP_ */
