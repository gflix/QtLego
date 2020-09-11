#ifndef FORMS_DEVICESELECTION_HPP_
#define FORMS_DEVICESELECTION_HPP_

#include <QtWidgets/QDialog>
#include <controllers/BluetoothDiscoveryController.hpp>

namespace Ui {
    class DeviceSelection;
}

namespace Lego
{

class DeviceSelection: public QDialog
{
    Q_OBJECT

public:
    DeviceSelection(
        const QBluetoothDeviceInfos& discoveredDevices,
        QWidget* parent = nullptr,
        Qt::WindowFlags f = Qt::WindowFlags());
    virtual ~DeviceSelection();

protected:

private:
    Ui::DeviceSelection* m_ui;

};

} /* namespace Lego */

#endif /* FORMS_DEVICESELECTION_HPP_ */
