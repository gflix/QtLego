#ifndef PROTOCOLS_SYSTEMTYPE_HPP_
#define PROTOCOLS_SYSTEMTYPE_HPP_

#include <QtCore/QString>
#include <models/SystemType.hpp>

namespace Lego
{

QString systemTypeToIdentifier(SystemType value);
SystemType systemTypeFromIdentifier(const QString& identifier);

} /* namespace Lego */

#endif /* PROTOCOLS_SYSTEMTYPE_HPP_ */
