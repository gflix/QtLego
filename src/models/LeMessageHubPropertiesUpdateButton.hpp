#ifndef MODELS_LEMESSAGEHUBPROPERTIESUPDATEBUTTON_HPP_
#define MODELS_LEMESSAGEHUBPROPERTIESUPDATEBUTTON_HPP_

#include <models/GenericLeMessageHubProperties.hpp>

namespace Lego
{

struct LeMessageHubPropertiesUpdateButton: public GenericLeMessageHubProperties
{
    LeMessageHubPropertiesUpdateButton();

    bool pressed;

    void dump(QTextStream& stream) const override;
};

} /* namespace Lego */

#endif /* MODELS_LEMESSAGEHUBPROPERTIESUPDATEBUTTON_HPP_ */
