#include <controllers/BluetoothController.hpp>
#include <protocols/GenericLeMessage.hpp>

namespace Lego
{

const QBluetoothUuid BluetoothController::m_legoService =
    QBluetoothUuid(QString("{00001623-1212-efde-1623-785feabcd123}"));
const QBluetoothUuid BluetoothController::m_legoCharacteristic =
    QBluetoothUuid(QString("{00001624-1212-efde-1623-785feabcd123}"));

BluetoothController::BluetoothController(QObject* parent):
    QObject(parent),
    m_leController(nullptr),
    m_foundService(false),
    m_leService(nullptr)
{
    connect(
        this, &BluetoothController::connected,
        this, &BluetoothController::enableNotifications);
}

BluetoothController::~BluetoothController()
{
    disconnectFromDevice();
}

void BluetoothController::connectToDevice(const QBluetoothDeviceInfo& device)
{
    disconnectFromDevice();
    if (!device.isValid())
    {
        throw std::invalid_argument("invalid device");
    }

    m_leController = QLowEnergyController::createCentral(device, this);

    connect(
        m_leController, &QLowEnergyController::serviceDiscovered,
        this, &BluetoothController::serviceDiscovered);
    connect(
        m_leController, &QLowEnergyController::discoveryFinished,
        this, &BluetoothController::scanFinished);

    connect(
        m_leController, static_cast<void (QLowEnergyController::*)(QLowEnergyController::Error)>
            (&QLowEnergyController::error),
        this, [](QLowEnergyController::Error) {
            qWarning() << "Cannot connect to remote device.";
        });
    connect(
        m_leController, &QLowEnergyController::connected,
        this, [this]() {
            qInfo() <<"Controller connected. Search services...";
            m_leController->discoverServices();
        });
    connect(
        m_leController, &QLowEnergyController::disconnected,
        this, []() {
            qWarning() << "LowEnergy controller disconnected";
        });

    m_leController->connectToDevice();
}

void BluetoothController::disconnectFromDevice(void)
{
    m_foundService = false;
    disconnectFromService();

    if (!m_leController)
    {
        return;
    }

    m_leController->disconnectFromDevice();
    connect(this, &BluetoothController::destroyed, m_leController, &QLowEnergyController::deleteLater);
    m_leController = nullptr;
}

void BluetoothController::sendMessage(const QByteArray& data)
{
    if (m_leService && m_leCharacteristic.isValid())
    {
        writeLegoCharacteristic(data);
    }
}

void BluetoothController::serviceDiscovered(const QBluetoothUuid& uuid)
{
    if (uuid == m_legoService)
    {
        m_foundService = true;
    }
}

void BluetoothController::scanFinished()
{
    if (m_foundService)
    {
        connectToService(m_legoService);
    }
    else
    {
        qWarning() << "Expected service not found!";
    }
}

void BluetoothController::connectToService(const QBluetoothUuid& uuid)
{
    disconnectFromService();
    if (!m_leController)
    {
        throw std::runtime_error("cannot connect to BLE service without a controller");
    }

    m_leService = m_leController->createServiceObject(uuid, this);
    if (!m_leService)
    {
        return;
    }

    connect(
        m_leService, &QLowEnergyService::stateChanged,
        this, &BluetoothController::serviceStateChanged);
    connect(
        m_leService, static_cast<void (QLowEnergyService::*)(QLowEnergyService::ServiceError)>
            (&QLowEnergyService::error),
        this, [](QLowEnergyService::ServiceError error) {
            qWarning() << "LowEnergy service error" << error;
        });

    m_leService->discoverDetails();
}

void BluetoothController::disconnectFromService(void)
{
    if (!m_leService)
    {
        return;
    }

    delete m_leService;
    m_leService = nullptr;
}

void BluetoothController::writeLegoCharacteristic(const QByteArray& data)
{
    if (!m_leService || !m_leCharacteristic.isValid())
    {
        throw std::runtime_error("bluetooth LE service or LEGO charactistic are invalid");
    }

    qInfo() << "BluetoothController::writeLegoCharacteristic(" << data.toHex() << ")";
    m_leService->writeCharacteristic(m_leCharacteristic, data);
}

void BluetoothController::serviceStateChanged(QLowEnergyService::ServiceState state)
{
    if (state == QLowEnergyService::ServiceDiscovered)
    {
        m_leCharacteristic = m_leService->characteristic(m_legoCharacteristic);
        if (!m_leCharacteristic.isValid())
        {
            return;
        }

        emit connected();

        writeLegoCharacteristic(QByteArray::fromHex("0500010605"));  // request battery level
        writeLegoCharacteristic(QByteArray::fromHex("0500010105"));  // request advertised name
        writeLegoCharacteristic(QByteArray::fromHex("0500010b05"));  // request device type
        writeLegoCharacteristic(QByteArray::fromHex("0500010202"));  // enable button updates
    }
}

void BluetoothController::enableNotifications(void)
{
    auto notification = m_leCharacteristic.descriptor(QBluetoothUuid::ClientCharacteristicConfiguration);
    if (!notification.isValid())
    {
        qWarning() << "Notification descriptor not found!";
        return;
    }

    connect(
        m_leService, &QLowEnergyService::characteristicChanged,
        this, &BluetoothController::characteristicChanged);

    // m_leService->writeDescriptor(notification, QByteArray::fromHex("0000"));
    m_leService->writeDescriptor(notification, QByteArray::fromHex("0100"));
}

void BluetoothController::characteristicChanged(const QLowEnergyCharacteristic& characteristic, const QByteArray& newValue)
{
    if (!characteristic.isValid())
    {
        qInfo() << "BluetoothController::characteristicChanged(invalid)";
        return;
    }
    if (characteristic != m_leCharacteristic)
    {
        qInfo() << "BluetoothController::characteristicChanged(different:" << characteristic.uuid() << ")";
        return;
    }

    emit messageReceived(newValue);

    QString dump;
    QTextStream stream(&dump);
    try
    {
        stream << decodeLeMessage(newValue);
        qInfo() <<
            "BluetoothController::characteristicChanged(" <<
            newValue.toHex() << ":" <<
            dump << ")";
    }
    catch(const std::exception& e)
    {
        qWarning() << "BluetoothController::characteristicChanged(" <<
            newValue.toHex() << ":" <<
            e.what() << ")";
    }
}

} /* namespace Lego */
