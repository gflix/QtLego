#ifndef MODELS_RGBLIGHTCOLOR_HPP_
#define MODELS_RGBLIGHTCOLOR_HPP_

#include <QtCore/QList>
#include <QtCore/QTextStream>

namespace Lego
{

enum class RgbLightColor
{
    UNKNOWN = -1,
    OFF = 0,
    PINK = 1,
    PURPLE = 2,
    BLUE = 3,
    CYAN = 4,
    TURQUOISE = 5,
    GREEN = 6,
    YELLOW = 7,
    AMBER = 8,
    RED = 9,
    WHITE = 10,
};

typedef QList<RgbLightColor> RgbLightColors;

QTextStream& operator<<(QTextStream& stream, RgbLightColor value);

} /* namespace Lego */

#endif /* MODELS_RGBLIGHTCOLOR_HPP_ */
