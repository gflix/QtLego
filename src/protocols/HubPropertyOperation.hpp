#ifndef PROTOCOLS_HUBPROPERTYOPERATION_HPP_
#define PROTOCOLS_HUBPROPERTYOPERATION_HPP_

#include <QtCore/QString>
#include <models/HubPropertyOperation.hpp>

namespace Lego
{

QString hubPropertyOperationToIdentifier(HubPropertyOperation value);
HubPropertyOperation hubPropertyOperationFromIdentifier(const QString& identifier);

} /* namespace Lego */

#endif /* PROTOCOLS_HUBPROPERTYOPERATION_HPP_ */
