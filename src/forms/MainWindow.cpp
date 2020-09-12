#include <QtCore/QDebug>
#include <QtWidgets/QMessageBox>
#include <forms/DeviceSelection.hpp>
#include <forms/MainWindow.hpp>
#include "ui_MainWindow.h"

namespace Lego
{

MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_bluetoothDiscoveryController(this)
{
    m_ui->setupUi(this);
    fixupUi();
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::btnConnectClicked(void)
{
    m_ui->btnConnect->setEnabled(false);
    m_bluetoothDiscoveryController.startDeviceDiscovery();
}

void MainWindow::deviceDiscoveryFinished(void)
{
    m_ui->btnConnect->setEnabled(true);
    const auto& discoveredDevices = m_bluetoothDiscoveryController.discoveredDevices();

    if (discoveredDevices.empty())
    {
        QMessageBox::warning(
            this,
            "No device found",
            "No suitable device found! "
            "Make sure the device is turned on and has the pairing mode enabled.");
    }
    else if (discoveredDevices.count() == 1)
    {
        m_bluetoothController.connectToDevice(discoveredDevices.first());
    }
    else
    {
        DeviceSelection deviceSelection { discoveredDevices };
        if (deviceSelection.exec() == QDialog::Accepted)
        {
            m_bluetoothController.connectToDevice(deviceSelection.selectedDevice());
        }
    }

}

void MainWindow::fixupUi(void)
{
    m_generalInformation = new GeneralInformation();
    m_ui->cGeneralInformation->addWidget(m_generalInformation);

    connect(
        &m_bluetoothDiscoveryController, &BluetoothDiscoveryController::deviceDiscoveryFinished,
        this, &MainWindow::deviceDiscoveryFinished);

    connect(
        &m_bluetoothController, &BluetoothController::messageReceived,
        m_generalInformation, &GeneralInformation::messageReceived);
}

} /* namespace Lego */
