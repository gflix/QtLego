#include <QtCore/QDebug>
#include <controllers/BluetoothDiscoveryController.hpp>

#define DISCOVERY_TIMEOUT (2000)

namespace Lego
{

QBluetoothAddresses BluetoothDiscoveryController::acceptedVendors = {
    QBluetoothAddress("90:84:2b:00:00:00"),  // LEGO System A/S
    QBluetoothAddress("00:16:53:00:00:00"),  // LEGO System A/S IE Electronics Division
    QBluetoothAddress("60:77:71:00:00:00"),  // Texas Instruments
};

BluetoothDiscoveryController::BluetoothDiscoveryController(QObject* parent):
    QObject(parent),
    m_discoveryPending(false),
    m_discoveryAgent(this)
{
    m_discoveryAgent.setLowEnergyDiscoveryTimeout(DISCOVERY_TIMEOUT);

    connect(
        &m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
        this, &BluetoothDiscoveryController::deviceDiscovered);
    connect(
        &m_discoveryAgent, static_cast<void (QBluetoothDeviceDiscoveryAgent::*)(QBluetoothDeviceDiscoveryAgent::Error)>
            (&QBluetoothDeviceDiscoveryAgent::error),
        this, &BluetoothDiscoveryController::scanError);

    connect(
        &m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
        this, &BluetoothDiscoveryController::scanFinished);
    connect(
        &m_discoveryAgent, &QBluetoothDeviceDiscoveryAgent::canceled,
        this, &BluetoothDiscoveryController::scanFinished);
}

BluetoothDiscoveryController::~BluetoothDiscoveryController()
{
}

const QBluetoothDeviceInfos& BluetoothDiscoveryController::discoveredDevices(void) const
{
    return m_discoveredDevices;
}

void BluetoothDiscoveryController::startDeviceDiscovery(void)
{
    if (m_discoveryPending)
    {
        return;
    }

    m_discoveryPending = true;
    m_discoveredDevices.clear();
    m_discoveryAgent.start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
}

void BluetoothDiscoveryController::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    const auto deviceAddress = device.address();

    for (auto& acceptedVendor: acceptedVendors)
    {
        if (vendorIdMatches(deviceAddress, acceptedVendor))
        {
            if (!m_discoveredDevices.contains(deviceAddress) ||
                m_discoveredDevices[deviceAddress].name().isEmpty())
            {
                m_discoveredDevices[deviceAddress] = device;
            }
            break;
        }
    }
}

void BluetoothDiscoveryController::scanError(QBluetoothDeviceDiscoveryAgent::Error error)
{
    m_discoveryPending = false;
    emit deviceDiscoveryFinished();
}

void BluetoothDiscoveryController::scanFinished()
{
    m_discoveryPending = false;
    emit deviceDiscoveryFinished();
}

bool BluetoothDiscoveryController::vendorIdMatches(const QBluetoothAddress& a, const QBluetoothAddress& b)
{
    return
        (a.toUInt64() & 0xffffff000000) == (b.toUInt64() & 0xffffff000000);
}

} /* namespace Lego */
