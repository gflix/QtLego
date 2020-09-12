#ifndef PROTOCOLS_HUBPROPERTY_HPP_
#define PROTOCOLS_HUBPROPERTY_HPP_

#include <QtCore/QString>
#include <models/HubProperty.hpp>

namespace Lego
{

QString hubPropertyToIdentifier(HubProperty value);
HubProperty hubPropertyFromIdentifier(const QString& identifier);

} /* namespace Lego */

#endif /* PROTOCOLS_HUBPROPERTY_HPP_ */
