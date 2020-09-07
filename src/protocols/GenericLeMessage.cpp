#include <protocols/GenericLeMessage.hpp>

namespace Lego
{

QPair<int, int> extractFrameMetrics(const QByteArray& data)
{
    auto dataSize = data.size();
    if (dataSize == 0)
    {
        throw std::invalid_argument("could not extract frame metrics from empty byte array");
    }

    int sizeBytes = 1;
    int frameSize = static_cast<unsigned char>(data[0]);
    if (frameSize & 0x80)
    {
        if (dataSize < 2)
        {
            throw std::invalid_argument("could not extract two byte frame size value from byte array");
        }
        ++sizeBytes;
        frameSize |= static_cast<unsigned char>(data[1]) << 7;
    }

    return QPair<int, int>(frameSize, sizeBytes);
}

LeMessage decodeLeMessage(const QByteArray& data)
{
    auto frameMetrics = extractFrameMetrics(data);

    throw std::runtime_error("decoder not yet implemented");
}

} /* namespace Lego */
