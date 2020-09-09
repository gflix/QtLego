#ifndef PROTOCOLS_GENERICLEMESSAGEHUBPROPERTIES_HPP_
#define PROTOCOLS_GENERICLEMESSAGEHUBPROPERTIES_HPP_

#include <QtCore/QByteArray>
#include <models/GenericLeMessage.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubProperties(const QByteArray& data);

} /* namespace Lego */

#endif /* PROTOCOLS_GENERICLEMESSAGEHUBPROPERTIES_HPP_ */
