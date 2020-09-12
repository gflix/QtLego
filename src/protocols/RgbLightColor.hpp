#ifndef PROTOCOLS_RGBLIGHTCOLOR_HPP_
#define PROTOCOLS_RGBLIGHTCOLOR_HPP_

#include <QtCore/QString>
#include <models/RgbLightColor.hpp>

namespace Lego
{

QString rgbLightColorToIdentifier(RgbLightColor value);
RgbLightColor rgbLightColorFromIdentifier(const QString& identifier);
RgbLightColors getRgbLightColors(void);

} /* namespace Lego */

#endif /* PROTOCOLS_RGBLIGHTCOLOR_HPP_ */
