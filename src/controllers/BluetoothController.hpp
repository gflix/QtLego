#ifndef CONTROLLERS_BLUETOOTHCONTROLLER_HPP_
#define CONTROLLERS_BLUETOOTHCONTROLLER_HPP_

#include <QtBluetooth/QBluetoothDeviceDiscoveryAgent>

namespace Lego
{

typedef QList<QBluetoothAddress> QBluetoothAddresses;
typedef QList<QBluetoothDeviceInfo> QBluetoothDeviceInfos;

class BluetoothController: public QObject
{
    Q_OBJECT

public:
    explicit BluetoothController(QObject* parent = nullptr);
    ~BluetoothController();

    const QBluetoothDeviceInfos& discoveredDevices(void) const;

public slots:
    void startDeviceDiscovery(void);

signals:
    void deviceDiscoveryFinished(void);

protected:

protected slots:
    void deviceDiscovered(const QBluetoothDeviceInfo &device);
    void scanError(QBluetoothDeviceDiscoveryAgent::Error error);
    void scanFinished();

private:
    bool m_discoveryPending;

    QBluetoothDeviceDiscoveryAgent m_discoveryAgent;
    QBluetoothDeviceInfos m_discoveredDevices;

    static QBluetoothAddresses acceptedVendors;

    static bool vendorIdMatches(const QBluetoothAddress& a, const QBluetoothAddress& b);
};

} /* namespace Lego */

#endif /* CONTROLLERS_BLUETOOTHCONTROLLER_HPP_ */
