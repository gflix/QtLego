#ifndef UTILS_ENUMMAPPER_HPP_
#define UTILS_ENUMMAPPER_HPP_

#include <QtCore/QMap>
#include <QtCore/QString>

namespace Lego
{

template<typename T>
T enumFromIdentifier(
    const QMap<QString, T>& mapping,
    const QString& identifier)
{
    auto value = mapping.find(identifier);
    if (value == mapping.constEnd())
    {
        throw std::out_of_range("\"" + identifier.toStdString() + "\" is an invalid identifier");
    }
    return value.value();
}

template<typename T>
T enumFromIdentifierWithDefault(
    const QMap<QString, T>& mapping,
    const QString& identifier,
    T defaultValue)
{
    try
    {
        return enumFromIdentifier(mapping, identifier);
    }
    catch (std::out_of_range)
    {
        return defaultValue;
    }
}

template<typename T>
const QString& enumToIdentifier(
    const QMap<QString, T>& mapping,
    T value)
{
    QString identifier;
    auto entry = mapping.constBegin();
    for (; entry != mapping.constEnd(); ++entry)
    {
        if (entry.value() == value)
        {
            return entry.key();
        }
    }

    throw std::out_of_range("no identifier for given enum value found");
}

template<typename T>
const QString& enumToIdentifierWithDefault(
    const QMap<QString, T>& mapping,
    T value,
    const QString& defaultIdentifier)
{
    try
    {
        return enumToIdentifier(mapping, value);
    }
    catch (std::out_of_range)
    {
        return defaultIdentifier;
    }
}

} /* namespace Lego */

#endif /* UTILS_ENUMMAPPER_HPP_ */
