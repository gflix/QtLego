#include <QtCore/QDebug>
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
        if (auto updateBatteryLevel = tryCast<LeMessageHubPropertiesUpdateBatteryLevel>(leMessage))
        {
            m_ui->lbBatteryPercentage->setText(QString("%1%").arg(updateBatteryLevel->batteryLevel));
        }
    }
    catch(const std::exception&)
    {
    }
}

} /* namespace Lego */
