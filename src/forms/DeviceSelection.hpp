#ifndef FORMS_DEVICESELECTION_HPP_
#define FORMS_DEVICESELECTION_HPP_

#include <QtWidgets/QDialog>
#include <controllers/BluetoothDiscoveryController.hpp>
#include <models/lists/BluetoothDeviceList.hpp>

namespace Ui {
    class DeviceSelection;
}

namespace Lego
{

class DeviceSelection: public QDialog
{
    Q_OBJECT

public:
    explicit DeviceSelection(
        const QBluetoothDeviceInfos& discoveredDevices,
        QWidget* parent = nullptr,
        Qt::WindowFlags f = Qt::WindowFlags());
    virtual ~DeviceSelection();

    QBluetoothDeviceInfo selectedDevice(void) const;

protected:

private:
    Ui::DeviceSelection* m_ui;
    BluetoothDeviceList m_deviceList;

};

} /* namespace Lego */

#endif /* FORMS_DEVICESELECTION_HPP_ */
