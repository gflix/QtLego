#ifndef MODELS_LEMESSAGEHUBPROPERTIESUPDATEBATTERYLEVEL_HPP_
#define MODELS_LEMESSAGEHUBPROPERTIESUPDATEBATTERYLEVEL_HPP_

#include <models/GenericLeMessageHubProperties.hpp>

namespace Lego
{

struct LeMessageHubPropertiesUpdateBatteryLevel: public GenericLeMessageHubProperties
{
    LeMessageHubPropertiesUpdateBatteryLevel();

    int batteryLevel;

    void dump(QTextStream& stream) const override;
};

} /* namespace Lego */

#endif /* MODELS_LEMESSAGEHUBPROPERTIESUPDATEBATTERYLEVEL_HPP_ */
