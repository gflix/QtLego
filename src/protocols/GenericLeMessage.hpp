#ifndef PROTOCOLS_GENERICLEMESSAGE_HPP_
#define PROTOCOLS_GENERICLEMESSAGE_HPP_

#include <QtCore/QByteArray>
#include <QtCore/QPair>
#include <models/GenericLeMessage.hpp>

namespace Lego
{

typedef QPair<int, int> FrameMetrics;

FrameMetrics extractFrameMetrics(const QByteArray& data);
void checkFrameMetrics(const QByteArray& data, const FrameMetrics& frameMetrics);
LeMessage decodeLeMessage(const QByteArray& data);

} /* namespace Lego */

#endif /* PROTOCOLS_GENERICLEMESSAGE_HPP_ */
