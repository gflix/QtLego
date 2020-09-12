#ifndef FORMS_GENERALINFORMATION_HPP_
#define FORMS_GENERALINFORMATION_HPP_

#include <forms/GenericChildDialog.hpp>
#include <models/LeMessageHubPropertiesUpdateAdvertisingName.hpp>
#include <models/LeMessageHubPropertiesUpdateBatteryLevel.hpp>
#include <models/LeMessageHubPropertiesUpdateButton.hpp>
#include <models/LeMessageHubPropertiesUpdateSystemType.hpp>

namespace Ui {
    class GeneralInformation;
}

namespace Lego
{

class GeneralInformation: public GenericChildDialog
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
    void processLeMessageHubPropertiesUpdateButton(
        const LeMessageHubPropertiesUpdateButton& message);
    void processLeMessageHubPropertiesUpdateSystemType(
        const LeMessageHubPropertiesUpdateSystemType& message);
};

} /* namespace Lego */

#endif /* FORMS_GENERALINFORMATION_HPP_ */
