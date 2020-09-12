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
    m_generalInformation(nullptr),
    m_bluetoothDiscoveryController(this)
{
    m_ui->setupUi(this);
    fixupUi();
}

MainWindow::~MainWindow()
{
    destroyChildDialogs();
    delete m_ui;
}

void MainWindow::btnConnectClicked(void)
{
    destroyChildDialogs();
    m_ui->btnConnect->setEnabled(false);
    m_bluetoothController.disconnectFromDevice();
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

void MainWindow::deviceConnected(void)
{
    destroyChildDialogs();
    createGeneralInformationDialog();
}

void MainWindow::fixupUi(void)
{
    connect(
        &m_bluetoothDiscoveryController, &BluetoothDiscoveryController::deviceDiscoveryFinished,
        this, &MainWindow::deviceDiscoveryFinished);
    connect(
        &m_bluetoothController, &BluetoothController::connected,
        this, &MainWindow::deviceConnected);
}

void MainWindow::createGeneralInformationDialog(void)
{
    if (m_generalInformation)
    {
        throw std::runtime_error("general information dialog already exists");
    }

    m_generalInformation = new GeneralInformation(this);
    connect(
        &m_bluetoothController, &BluetoothController::messageReceived,
        m_generalInformation, &GeneralInformation::messageReceived);
    m_generalInformation->show();
}

void MainWindow::destroyChildDialogs(void)
{
    if (m_generalInformation)
    {
        m_generalInformation->close();
        delete m_generalInformation;
        m_generalInformation = nullptr;
    }
}

} /* namespace Lego */
