#include <controllers/BluetoothController.hpp>

#define DISCOVERY_TIMEOUT (5000)

namespace Lego
{

BluetoothController::BluetoothController(QObject* parent):
    QObject(parent),
    m_discoveryAgent(this)
{
    m_discoveryAgent.setLowEnergyDiscoveryTimeout(DISCOVERY_TIMEOUT);
}

BluetoothController::~BluetoothController()
{
}

} /* namespace Lego */
