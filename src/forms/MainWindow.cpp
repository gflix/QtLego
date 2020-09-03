#include <forms/MainWindow.hpp>
#include "ui_MainWindow.h"

namespace Lego
{

MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    bluetoothController(this)
{
    ui->setupUi(this);
    fixupUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fixupUi(void)
{
}

} /* namespace Lego */
