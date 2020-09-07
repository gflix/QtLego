#ifndef PROTOCOLS_GENERICLEMESSAGE_HPP_
#define PROTOCOLS_GENERICLEMESSAGE_HPP_

#include <QtCore/QByteArray>
#include <QtCore/QPair>
#include <models/GenericLeMessage.hpp>

namespace Lego
{

QPair<int, int> extractFrameMetrics(const QByteArray& data);
LeMessage decodeLeMessage(const QByteArray& data);

} /* namespace Lego */

#endif /* PROTOCOLS_GENERICLEMESSAGE_HPP_ */
