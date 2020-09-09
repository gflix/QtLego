#ifndef UTILS_CONVERTER_HPP_
#define UTILS_CONVERTER_HPP_

#include <QtCore/QByteArray>
#include <QtCore/QString>

namespace Lego
{

class Converter
{
public:
    static unsigned char byteArrayToUnsignedChar(const QByteArray& data);
    static char byteArrayToChar(const QByteArray& data);

    static unsigned short byteArrayToUnsignedShortLe(const QByteArray& data);

    static QString byteArrayToString(const QByteArray& data);
};

} /* namespace Lego */

#endif /* UTILS_CONVERTER_HPP_ */
