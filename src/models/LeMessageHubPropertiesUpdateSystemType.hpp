#ifndef MODELS_LEMESSAGEHUBPROPERTIESUPDATESYSTEMTYPE_HPP_
#define MODELS_LEMESSAGEHUBPROPERTIESUPDATESYSTEMTYPE_HPP_

#include <models/GenericLeMessageHubProperties.hpp>
#include <models/SystemType.hpp>

namespace Lego
{

struct LeMessageHubPropertiesUpdateSystemType: public GenericLeMessageHubProperties
{
    LeMessageHubPropertiesUpdateSystemType();

    SystemType systemType;

    void dump(QTextStream& stream) const override;
};

} /* namespace Lego */

#endif /* MODELS_LEMESSAGEHUBPROPERTIESUPDATESYSTEMTYPE_HPP_ */
