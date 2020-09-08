#ifndef PROTOCOLS_GENERICLEMESSAGEHUBATTACHEDIO_HPP_
#define PROTOCOLS_GENERICLEMESSAGEHUBATTACHEDIO_HPP_

#include <QtCore/QByteArray>
#include <models/GenericLeMessage.hpp>

namespace Lego
{

LeMessage decodeLeMessageHubAttachedIo(const QByteArray& data);

} /* namespace Lego */

#endif /* PROTOCOLS_GENERICLEMESSAGEHUBATTACHEDIO_HPP_ */
