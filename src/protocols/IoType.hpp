#ifndef PROTOCOLS_IOTYPE_HPP_
#define PROTOCOLS_IOTYPE_HPP_

#include <QtCore/QString>
#include <models/IoType.hpp>

namespace Lego
{

QString ioTypeToIdentifier(IoType value);
IoType ioTypeFromIdentifier(const QString& identifier);

} /* namespace Lego */

#endif /* PROTOCOLS_IOTYPE_HPP_ */
