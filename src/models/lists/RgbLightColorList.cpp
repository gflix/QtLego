#include <models/lists/RgbLightColorList.hpp>
#include <protocols/RgbLightColor.hpp>

namespace Lego
{

RgbLightColorList::RgbLightColorList(
    const RgbLightColors& rgbLightColors,
    QObject* parent):
    QAbstractListModel(parent),
    m_rgbLightColors(rgbLightColors)
{
}

int RgbLightColorList::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
    {
        return 0;
    }

    return m_rgbLightColors.count();
}

RgbLightColor RgbLightColorList::get(int row) const
{
    return get(index(row, 0));
}

RgbLightColor RgbLightColorList::get(const QModelIndex& index) const
{
    if (!index.isValid())
    {
        throw std::invalid_argument("invalid index");
    }

    return m_rgbLightColors[index.row()];
}

QVariant RgbLightColorList::data(const QModelIndex &index, int role) const
{
    try
    {
        return rgbLightColorToIdentifier(get(index));;
    }
    catch(const std::exception&)
    {
        return QVariant();
    }
}

} /* namespace Lego */
