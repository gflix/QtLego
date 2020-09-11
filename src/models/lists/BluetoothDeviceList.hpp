#ifndef MODELS_LISTS_BLUETOOTHDEVICELIST_HPP_
#define MODELS_LISTS_BLUETOOTHDEVICELIST_HPP_

#include <QtCore/QAbstractListModel>
#include <controllers/BluetoothDiscoveryController.hpp>

namespace Lego
{

class BluetoothDeviceList: public QAbstractListModel
{
    Q_OBJECT

public:
    explicit BluetoothDeviceList(
        const QBluetoothDeviceInfos& bluetoothDevices,
        QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QBluetoothDeviceInfo get(int row) const;
    QBluetoothDeviceInfo get(const QModelIndex &index) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    const QBluetoothDeviceInfos& m_bluetoothDevices;
};

} /* namespace Lego */

#endif /* MODELS_LISTS_BLUETOOTHDEVICELIST_HPP_ */
