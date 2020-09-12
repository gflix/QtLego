#ifndef FORMS_MAINWINDOW_HPP_
#define FORMS_MAINWINDOW_HPP_

#include <QtWidgets/QMainWindow>
#include <controllers/BluetoothController.hpp>
#include <controllers/BluetoothDiscoveryController.hpp>
#include <forms/GeneralInformation.hpp>
#include <models/LeMessageHubAttachedIo.hpp>

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
    virtual ~MainWindow();

protected:

protected slots:
    void btnConnectClicked(void);
    void deviceDiscoveryFinished(void);
    void deviceConnected(void);
    void messageReceived(const QByteArray& data);

private:
    Ui::MainWindow* m_ui;
    GeneralInformation* m_generalInformation;
    AttachedIoChildDialogs m_attachedIoChildDialogs;

    BluetoothDiscoveryController m_bluetoothDiscoveryController;
    BluetoothController m_bluetoothController;

    void fixupUi(void);
    void createGeneralInformationDialog(void);
    void destroyChildDialogs(void);

    void processLeMessageHubAttachedIo(
        const LeMessageHubAttachedIo& message);
};

} /* namespace Lego */

#endif /* FORMS_MAINWINDOW_HPP_ */
