#include <QtCore/QDebug>
#include <forms/MainWindow.hpp>
#include "ui_MainWindow.h"

namespace Lego
{

MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_bluetoothController(this)
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
    m_bluetoothController.startDeviceDiscovery();
}

void MainWindow::deviceDiscoveryFinished(void)
{
    m_ui->btnConnect->setEnabled(true);
    const auto& discoveredDevices = m_bluetoothController.discoveredDevices();

    if (discoveredDevices.count() == 1)
    {
    }
}

void MainWindow::fixupUi(void)
{
    connect(
        &m_bluetoothController, &BluetoothController::deviceDiscoveryFinished,
        this, &MainWindow::deviceDiscoveryFinished);
}

} /* namespace Lego */
