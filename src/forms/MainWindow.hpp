#ifndef FORMS_MAINWINDOW_HPP_
#define FORMS_MAINWINDOW_HPP_

#include <QtWidgets/QMainWindow>
#include <controllers/BluetoothController.hpp>

namespace Ui {
    class MainWindow;
}

namespace Lego
{

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:

private:
    Ui::MainWindow* ui;

    BluetoothController bluetoothController;

    void fixupUi(void);
};

} /* namespace Lego */

#endif /* FORMS_MAINWINDOW_HPP_ */
