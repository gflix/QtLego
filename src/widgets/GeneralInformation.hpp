#ifndef WIDGETS_GENERALINFORMATION_HPP_
#define WIDGETS_GENERALINFORMATION_HPP_

#include <QtWidgets/QGroupBox>
#include <models/LeMessageHubPropertiesUpdateAdvertisingName.hpp>
#include <models/LeMessageHubPropertiesUpdateBatteryLevel.hpp>
#include <models/LeMessageHubPropertiesUpdateButton.hpp>

namespace Ui {
    class GeneralInformation;
}

namespace Lego
{

class GeneralInformation: public QGroupBox
{
    Q_OBJECT

public:
    explicit GeneralInformation(QWidget* parent = nullptr);
    virtual ~GeneralInformation();

public slots:
    void messageReceived(const QByteArray& data);

protected:

private:
    Ui::GeneralInformation* m_ui;

    void processLeMessageHubPropertiesUpdateAdvertisingName(
        const LeMessageHubPropertiesUpdateAdvertisingName& message);
    void processLeMessageHubPropertiesUpdateBatteryLevel(
        const LeMessageHubPropertiesUpdateBatteryLevel& message);
};

} /* namespace Lego */

#endif /* WIDGETS_GENERALINFORMATION_HPP_ */
