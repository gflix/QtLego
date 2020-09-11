#include <models/lists/BluetoothDeviceList.hpp>

namespace Lego
{

BluetoothDeviceList::BluetoothDeviceList(
    const QBluetoothDeviceInfos& bluetoothDevices,
    QObject* parent):
    QAbstractListModel(parent),
    m_bluetoothDevices(bluetoothDevices)
{
}

int BluetoothDeviceList::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
    {
        return 0;
    }

    return m_bluetoothDevices.count();
}

QBluetoothDeviceInfo BluetoothDeviceList::get(int row) const
{
    return get(index(row, 0));
}

QBluetoothDeviceInfo BluetoothDeviceList::get(const QModelIndex& index) const
{
    if (!index.isValid())
    {
        throw std::invalid_argument("invalid index");
    }

    return m_bluetoothDevices[m_bluetoothDevices.keys()[index.row()]];
}

QVariant BluetoothDeviceList::data(const QModelIndex &index, int role) const
{
    try
    {
        auto bluetoothDevice = get(index);
        return QString("%1 (%2)").arg(bluetoothDevice.name().trimmed(), bluetoothDevice.address().toString());
    }
    catch(const std::exception&)
    {
        return QVariant();
    }
}

} /* namespace Lego */
