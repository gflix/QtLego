#ifndef CONTROLLERS_BLUETOOTHCONTROLLER_HPP_
#define CONTROLLERS_BLUETOOTHCONTROLLER_HPP_

#include <QtBluetooth/QBluetoothDeviceDiscoveryAgent>

namespace Lego
{

class BluetoothController: public QObject
{
    Q_OBJECT

public:
    explicit BluetoothController(QObject* parent = nullptr);
    ~BluetoothController();

protected:

private:
    QBluetoothDeviceDiscoveryAgent m_discoveryAgent;

};

} /* namespace Lego */

#endif /* CONTROLLERS_BLUETOOTHCONTROLLER_HPP_ */
