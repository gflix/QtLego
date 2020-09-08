#ifndef MODELS_GENERICLEMESSAGE_HPP_
#define MODELS_GENERICLEMESSAGE_HPP_

#include <QtCore/QTextStream>
#include <QtCore/QSharedPointer>

namespace Lego
{

struct GenericLeMessage
{
    virtual ~GenericLeMessage() = default;

    virtual void dump(QTextStream& stream) const;
};

typedef QSharedPointer<GenericLeMessage> LeMessage;

QTextStream& operator<<(QTextStream& stream, const LeMessage& leMessage);

template<typename T>
T* cast(LeMessage leMessage)
{
    auto castedPointer = dynamic_cast<T*>(leMessage.data());
    if (!castedPointer)
    {
        throw std::runtime_error("invalid pointer after casting");
    }

    return castedPointer;
}

} /* namespace Lego */

#endif /* MODELS_GENERICLEMESSAGE_HPP_ */
