#include <QtCore/QDebug>
#include <models/LeMessageHubPropertiesUpdateAdvertisingName.hpp>
#include <models/LeMessageHubPropertiesUpdateBatteryLevel.hpp>
#include <protocols/GenericLeMessage.hpp>
#include <widgets/GeneralInformation.hpp>
#include "ui_GeneralInformation.h"

namespace Lego
{

GeneralInformation::GeneralInformation(QWidget* parent):
    QGroupBox(parent),
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
            m_ui->lbName->setText(message->advertisingName);
        }
        if (auto message = tryCast<LeMessageHubPropertiesUpdateBatteryLevel>(leMessage))
        {
            m_ui->lbBatteryPercentage->setText(QString("%1%").arg(message->batteryLevel));
        }
    }
    catch(const std::exception&)
    {
    }
}

} /* namespace Lego */
