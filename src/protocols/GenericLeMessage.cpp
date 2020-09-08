#include <protocols/GenericLeMessage.hpp>
#include <protocols/GenericLeMessageHubAttachedIo.hpp>
#include <utils/Converter.hpp>

namespace Lego
{

FrameMetrics extractFrameMetrics(const QByteArray& data)
{
    auto dataSize = data.size();
    if (dataSize == 0)
    {
        throw std::invalid_argument("could not extract frame metrics from empty byte array");
    }

    int sizeBytes = 1;
    int frameSize = Converter::byteArrayToUnsignedChar(data.mid(0, 1));
    if (frameSize & 0x80)
    {
        if (dataSize < 2)
        {
            throw std::invalid_argument("could not extract two byte frame size value from byte array");
        }
        ++sizeBytes;
        frameSize |= Converter::byteArrayToUnsignedChar(data.mid(1, 1)) << 7;
    }

    return FrameMetrics(frameSize, sizeBytes);
}

void checkFrameMetrics(const QByteArray& data, const FrameMetrics& frameMetrics)
{
    auto dataSize = data.size();

    if (dataSize < frameMetrics.first)
    {
        throw std::invalid_argument("could not decode LE message as the data is shorter than indicated");
    }
    if (dataSize > frameMetrics.first)
    {
        throw std::invalid_argument("could not decode LE message as the data is longer than indicated");
    }

    if (dataSize < (frameMetrics.second + 2))
    {
        throw std::invalid_argument("could not decode LE message as the header is invalid");
    }
}

LeMessage decodeLeMessage(const QByteArray& data)
{
    auto frameMetrics = extractFrameMetrics(data);
    checkFrameMetrics(data, frameMetrics);

    int hubId = data[frameMetrics.second];
    if (hubId != 0)
    {
        throw std::domain_error("could not decode LE message as a hub ID other than 0 is not yet supported");
    }

    auto payload = data.mid(frameMetrics.second + 2);
    int messageType = Converter::byteArrayToUnsignedChar(data.mid(frameMetrics.second + 1, 1));

    switch (messageType)
    {
        case 4:
            return decodeLeMessageHubAttachedIo(payload);
        default:
            break;
    }

    throw std::runtime_error("decoder not yet implemented");
}

} /* namespace Lego */
