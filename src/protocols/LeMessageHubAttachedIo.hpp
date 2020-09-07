#ifndef PROTOCOLS_LEMESSAGEHUBATTACHEDIO_HPP_
#define PROTOCOLS_LEMESSAGEHUBATTACHEDIO_HPP_

#include <QtCore/QByteArray>
#include <models/GenericLeMessage.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubAttachedIo(int port, const QByteArray& data);

} /* namespace Lego */

#endif /* PROTOCOLS_LEMESSAGEHUBATTACHEDIO_HPP_ */
