#include <utils/Converter.hpp>

namespace Lego
{

unsigned char Converter::byteArrayToUnsignedChar(const QByteArray& data)
{
    if (data.size() != 1)
    {
        throw std::invalid_argument("expect exactly 1 byte");
    }

    return static_cast<unsigned char>(data[0]);
}

char Converter::byteArrayToChar(const QByteArray& data)
{
    if (data.size() != 1)
    {
        throw std::invalid_argument("expect exactly 1 byte");
    }

    return data[0];
}

unsigned short Converter::byteArrayToUnsignedShortLe(const QByteArray& data)
{
    if (data.size() != 2)
    {
        throw std::invalid_argument("expect exactly 2 byte");
    }

    return
        (static_cast<unsigned char>(data[1]) << 8) |
        static_cast<unsigned char>(data[0]);
}

QString Converter::byteArrayToString(const QByteArray& data)
{
    return QString::fromUtf8(data);
}

} /* namespace Lego */
