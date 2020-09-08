#ifndef UTILS_CONVERTER_HPP_
#define UTILS_CONVERTER_HPP_

#include <QtCore/QByteArray>

namespace Lego
{

class Converter
{
public:
    static unsigned char byteArrayToUnsignedChar(const QByteArray& data);
};

} /* namespace Lego */

#endif /* UTILS_CONVERTER_HPP_ */
