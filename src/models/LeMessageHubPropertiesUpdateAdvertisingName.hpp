#ifndef MODELS_LEMESSAGEHUBPROPERTIESUPDATEADVERTISINGNAME_HPP_
#define MODELS_LEMESSAGEHUBPROPERTIESUPDATEADVERTISINGNAME_HPP_

#include <models/GenericLeMessageHubProperties.hpp>

namespace Lego
{

struct LeMessageHubPropertiesUpdateAdvertisingName: public GenericLeMessageHubProperties
{
    LeMessageHubPropertiesUpdateAdvertisingName();

    QString advertisingName;

    void dump(QTextStream& stream) const override;
};

} /* namespace Lego */

#endif /* MODELS_LEMESSAGEHUBPROPERTIESUPDATEADVERTISINGNAME_HPP_ */
