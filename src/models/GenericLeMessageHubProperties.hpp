#ifndef MODELS_GENERICLEMESSAGEHUBPROPERTIES_HPP_
#define MODELS_GENERICLEMESSAGEHUBPROPERTIES_HPP_

#include <models/GenericLeMessage.hpp>

namespace Lego
{

struct GenericLeMessageHubProperties: public GenericLeMessage
{
    GenericLeMessageHubProperties();

    int property;
    int operation;
};

} /* namespace Lego */

#endif /* MODELS_GENERICLEMESSAGEHUBPROPERTIES_HPP_ */
