#include <protocols/GenericLeMessage.hpp>
#include <protocols/SystemType.hpp>
#include <forms/GeneralInformation.hpp>
#include "ui_GeneralInformation.h"

namespace Lego
{

GeneralInformation::GeneralInformation(QWidget* parent):
    GenericChildDialog(parent),
    m_ui(new Ui::GeneralInformation)
{
    m_ui->setupUi(this);
}

GeneralInformation::~GeneralInformation()
{
}

void GeneralInformation::messageReceived(const QByteArray& data)
{
    try
    {
        auto leMessage = decodeLeMessage(data);
        if (auto message = tryCast<LeMessageHubPropertiesUpdateAdvertisingName>(leMessage))
        {
            processLeMessageHubPropertiesUpdateAdvertisingName(*message);
        }
        else if (auto message = tryCast<LeMessageHubPropertiesUpdateBatteryLevel>(leMessage))
        {
            processLeMessageHubPropertiesUpdateBatteryLevel(*message);
        }
        else if (auto message = tryCast<LeMessageHubPropertiesUpdateButton>(leMessage))
        {
            processLeMessageHubPropertiesUpdateButton(*message);
        }
        else if (auto message = tryCast<LeMessageHubPropertiesUpdateSystemType>(leMessage))
        {
            processLeMessageHubPropertiesUpdateSystemType(*message);
        }
    }
    catch(const std::exception&)
    {
    }
}

void GeneralInformation::processLeMessageHubPropertiesUpdateAdvertisingName(
    const LeMessageHubPropertiesUpdateAdvertisingName& message)
{
    m_ui->lbName->setText(message.advertisingName);
}

void GeneralInformation::processLeMessageHubPropertiesUpdateBatteryLevel(
    const LeMessageHubPropertiesUpdateBatteryLevel& message)
{
    m_ui->lbBatteryPercentage->setText(QString("%1%").arg(message.batteryLevel));
}

void GeneralInformation::processLeMessageHubPropertiesUpdateButton(
    const LeMessageHubPropertiesUpdateButton& message)
{
    m_ui->lbButton->setText(message.pressed ? "pressed" : "depressed");
}

void GeneralInformation::processLeMessageHubPropertiesUpdateSystemType(
    const LeMessageHubPropertiesUpdateSystemType& message)
{
    m_ui->lbSystemType->setText(systemTypeToIdentifier(message.systemType));
}

} /* namespace Lego */
