#ifndef MODELS_LEMESSAGEHUBDETACHEDIO_HPP_
#define MODELS_LEMESSAGEHUBDETACHEDIO_HPP_

#include <models/GenericLeMessageHubAttachedIo.hpp>

namespace Lego
{

struct LeMessageHubDetachedIo: public GenericLeMessageHubAttachedIo
{
    LeMessageHubDetachedIo();

    void dump(QTextStream& stream) const override;
};

} /* namespace Lego */

#endif /* MODELS_LEMESSAGEHUBDETACHEDIO_HPP_ */
