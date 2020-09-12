#ifndef MODELS_LISTS_RGBLIGHTCOLORLIST_HPP_
#define MODELS_LISTS_RGBLIGHTCOLORLIST_HPP_

#include <QtCore/QAbstractListModel>
#include <models/RgbLightColor.hpp>

namespace Lego
{

class RgbLightColorList: public QAbstractListModel
{
    Q_OBJECT

public:
    explicit RgbLightColorList(
        const RgbLightColors& rgbLightColors,
        QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    RgbLightColor get(int row) const;
    RgbLightColor get(const QModelIndex &index) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    RgbLightColors m_rgbLightColors;
};

} /* namespace Lego */

#endif /* MODELS_LISTS_RGBLIGHTCOLORLIST_HPP_ */
