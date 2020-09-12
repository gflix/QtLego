#ifndef MODELS_HUBPROPERTYOPERATION_HPP_
#define MODELS_HUBPROPERTYOPERATION_HPP_

#include <QtCore/QTextStream>

namespace Lego
{

enum class HubPropertyOperation
{
    UNKNOWN = -1,
    ENABLE_UPDATES = 0x02,
    REQUEST_UPDATE = 0x05,
    UPDATE = 0x06,
};

QTextStream& operator<<(QTextStream& stream, HubPropertyOperation value);

} /* namespace Lego */

#endif /* MODELS_HUBPROPERTYOPERATION_HPP_ */
