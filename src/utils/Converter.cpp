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

} /* namespace Lego */
