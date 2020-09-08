#include <models/GenericLeMessage.hpp>

namespace Lego
{

void GenericLeMessage::dump(QTextStream& stream) const
{
    stream << "GenericLeMessage[]";
}

QTextStream& operator<<(QTextStream& stream, const LeMessage& leMessage)
{
    if (leMessage.isNull())
    {
        stream << "GenericLeMessage[null]";
    }
    else
    {
        leMessage->dump(stream);
    }

    return stream;
}

} /* namespace Lego */
