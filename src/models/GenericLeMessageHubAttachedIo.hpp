#ifndef MODELS_GENERICLEMESSAGEHUBATTACHEDIO_HPP_
#define MODELS_GENERICLEMESSAGEHUBATTACHEDIO_HPP_

#include <models/GenericLeMessage.hpp>

namespace Lego
{

struct GenericLeMessageHubAttachedIo: public GenericLeMessage
{
    GenericLeMessageHubAttachedIo();

    int port;
};

} /* namespace Lego */

#endif /* MODELS_GENERICLEMESSAGEHUBATTACHEDIO_HPP_ */
