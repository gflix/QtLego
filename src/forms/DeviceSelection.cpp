#include <forms/DeviceSelection.hpp>
#include "ui_DeviceSelection.h"

namespace Lego
{

DeviceSelection::DeviceSelection(
    const QBluetoothDeviceInfos& discoveredDevices,
    QWidget* parent,
    Qt::WindowFlags windowFlags):
    QDialog(parent, windowFlags),
    m_ui(new Ui::DeviceSelection)
{
    m_ui->setupUi(this);
}

DeviceSelection::~DeviceSelection()
{
    delete m_ui;
}

} /* namespace Lego */
