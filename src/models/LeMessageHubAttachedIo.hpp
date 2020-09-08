#ifndef MODELS_LEMESSAGEHUBATTACHEDIO_HPP_
#define MODELS_LEMESSAGEHUBATTACHEDIO_HPP_

#include <models/GenericLeMessageHubAttachedIo.hpp>

namespace Lego
{

struct LeMessageHubAttachedIo: public GenericLeMessageHubAttachedIo
{
    LeMessageHubAttachedIo();

    int ioType;

    void dump(QTextStream& stream) const override;
};

} /* namespace Lego */

#endif /* MODELS_LEMESSAGEHUBATTACHEDIO_HPP_ */
