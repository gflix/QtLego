#include <forms/DeviceSelection.hpp>
#include "ui_DeviceSelection.h"

namespace Lego
{

DeviceSelection::DeviceSelection(
    const QBluetoothDeviceInfos& discoveredDevices,
    QWidget* parent,
    Qt::WindowFlags windowFlags):
    QDialog(parent, windowFlags),
    m_ui(new Ui::DeviceSelection),
    m_deviceList(discoveredDevices, this)
{
    m_ui->setupUi(this);
    m_ui->comboDiscoveredDevices->setModel(&m_deviceList);
}

DeviceSelection::~DeviceSelection()
{
    delete m_ui;
}

QBluetoothDeviceInfo DeviceSelection::selectedDevice(void) const
{
    return m_deviceList.get(m_ui->comboDiscoveredDevices->currentIndex());
}

} /* namespace Lego */
