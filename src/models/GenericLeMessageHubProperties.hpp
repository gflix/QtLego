#ifndef MODELS_GENERICLEMESSAGEHUBPROPERTIES_HPP_
#define MODELS_GENERICLEMESSAGEHUBPROPERTIES_HPP_

#include <models/GenericLeMessage.hpp>
#include <models/HubProperty.hpp>
#include <models/HubPropertyOperation.hpp>

namespace Lego
{

struct GenericLeMessageHubProperties: public GenericLeMessage
{
    GenericLeMessageHubProperties();

    HubProperty property;
    HubPropertyOperation operation;
};

} /* namespace Lego */

#endif /* MODELS_GENERICLEMESSAGEHUBPROPERTIES_HPP_ */
