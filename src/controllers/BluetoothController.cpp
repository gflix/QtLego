#include <QtCore/QDebug>
#include <controllers/BluetoothController.hpp>

#define DISCOVERY_TIMEOUT (5000)

namespace Lego
{

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

void BluetoothController::startDeviceDiscovery(void)
{
    if (m_discoveryPending)
    {
        return;
    }
    qInfo() << "BluetoothController::startDeviceDiscovery()";

    m_discoveryPending = true;
    m_discoveredDevices.clear();
    m_discoveryAgent.start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
}

void BluetoothController::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    qInfo() << "BluetoothController::deviceDiscovered(" << device.name() << ")";
    m_discoveredDevices.append(device);
}

void BluetoothController::scanError(QBluetoothDeviceDiscoveryAgent::Error error)
{
    qWarning() << "BluetoothController::scanError(" << error << ")";
}

void BluetoothController::scanFinished()
{
    m_discoveryPending = false;
    emit deviceDiscoveryFinished();
}

} /* namespace Lego */
