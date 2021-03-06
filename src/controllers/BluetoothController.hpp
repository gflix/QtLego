#ifndef CONTROLLERS_BLUETOOTHCONTROLLER_HPP_
#define CONTROLLERS_BLUETOOTHCONTROLLER_HPP_

#include <QtBluetooth/QLowEnergyController>

namespace Lego
{

class BluetoothController: public QObject
{
    Q_OBJECT

public:
    BluetoothController(QObject* parent = nullptr);
    ~BluetoothController();

    void connectToDevice(const QBluetoothDeviceInfo& device);
    void disconnectFromDevice(void);

public slots:
    void sendMessage(const QByteArray& data);

signals:
    void connected(void);
    void messageReceived(const QByteArray& data);

protected:

protected slots:
    void serviceDiscovered(const QBluetoothUuid &uuid);
    void scanFinished(void);

    void serviceStateChanged(QLowEnergyService::ServiceState state);

    void enableNotifications(void);
    void characteristicChanged(const QLowEnergyCharacteristic& characteristic, const QByteArray& newValue);

private:
    QLowEnergyController* m_leController;
    bool m_foundService;
    QLowEnergyService* m_leService;
    QLowEnergyCharacteristic m_leCharacteristic;

    static const QBluetoothUuid m_legoService;
    static const QBluetoothUuid m_legoCharacteristic;

    void connectToService(const QBluetoothUuid& uuid);
    void disconnectFromService(void);

    void writeLegoCharacteristic(const QByteArray& data);
};

} /* namespace Lego */

#endif /* CONTROLLERS_BLUETOOTHCONTROLLER_HPP_ */
