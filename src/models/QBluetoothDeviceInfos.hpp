#ifndef MODELS_QBLUETOOTHDEVICEINFOS_HPP_
#define MODELS_QBLUETOOTHDEVICEINFOS_HPP_

#include <QtBluetooth/QBluetoothDeviceInfo>
#include <QtCore/QMap>

namespace Lego
{

typedef QMap<QBluetoothAddress, QBluetoothDeviceInfo> QBluetoothDeviceInfos;

} /* namespace Lego */

#endif /* MODELS_QBLUETOOTHDEVICEINFOS_HPP_ */
