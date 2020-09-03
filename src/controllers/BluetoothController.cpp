#include <QtCore/QDebug>
#include <controllers/BluetoothController.hpp>

#define DISCOVERY_TIMEOUT (2000)

namespace Lego
{

QBluetoothAddresses BluetoothController::acceptedVendors = {
    QBluetoothAddress("90:84:2b:00:00:00"),  // LEGO System A/S
};

BluetoothController::BluetoothController(QObject* parent):
    QObject(parent),
    m_discoveryPending(false),
    m_discoveryAgent(this)
{
    m_discoveryAgent.setLowEnergyDiscoveryTimeout(DISCOVERY_TIMEOUT);

    connect(
        &m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
        this, &BluetoothController::deviceDiscovered);
    connect(
        &m_discoveryAgent, static_cast<void (QBluetoothDeviceDiscoveryAgent::*)(QBluetoothDeviceDiscoveryAgent::Error)>
            (&QBluetoothDeviceDiscoveryAgent::error),
        this, &BluetoothController::scanError);

    connect(
        &m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
        this, &BluetoothController::scanFinished);
    connect(
        &m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::canceled,
        this, &BluetoothController::scanFinished);
}

BluetoothController::~BluetoothController()
{
}

const QBluetoothDeviceInfos& BluetoothController::discoveredDevices(void) const
{
    return m_discoveredDevices;
}

void BluetoothController::startDeviceDiscovery(void)
{
    if (m_discoveryPending)
    {
        return;
    }

    m_discoveryPending = true;
    m_discoveredDevices.clear();
    m_discoveryAgent.start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
}

void BluetoothController::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    const auto deviceAddress = device.address();

    for (auto& acceptedVendor: acceptedVendors)
    {
        if (vendorIdMatches(deviceAddress, acceptedVendor))
        {
            m_discoveredDevices.append(device);
            break;
        }
    }
}

void BluetoothController::scanError(QBluetoothDeviceDiscoveryAgent::Error error)
{
    m_discoveryPending = false;
    emit deviceDiscoveryFinished();
}

void BluetoothController::scanFinished()
{
    m_discoveryPending = false;
    emit deviceDiscoveryFinished();
}

bool BluetoothController::vendorIdMatches(const QBluetoothAddress& a, const QBluetoothAddress& b)
{
    return
        (a.toUInt64() & 0xffffff000000) == (b.toUInt64() & 0xffffff000000);
}

} /* namespace Lego */
