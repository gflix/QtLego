#ifndef PROTOCOLS_LEMESSAGEHUBDETACHEDIO_HPP_
#define PROTOCOLS_LEMESSAGEHUBDETACHEDIO_HPP_

#include <QtCore/QByteArray>
#include <models/GenericLeMessage.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubDetachedIo(int port, const QByteArray& data);

} /* namespace Lego */

#endif /* PROTOCOLS_LEMESSAGEHUBDETACHEDIO_HPP_ */
