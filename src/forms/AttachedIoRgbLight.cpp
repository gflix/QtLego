#include <protocols/GenericLeMessage.hpp>
#include <forms/AttachedIoRgbLight.hpp>
#include "ui_AttachedIoRgbLight.h"

namespace Lego
{

AttachedIoRgbLight::AttachedIoRgbLight(QWidget* parent):
    GenericChildDialog(parent),
    m_ui(new Ui::AttachedIoRgbLight)
{
    m_ui->setupUi(this);
}

AttachedIoRgbLight::~AttachedIoRgbLight()
{
}

void AttachedIoRgbLight::messageReceived(const QByteArray& data)
{
    try
    {
        auto leMessage = decodeLeMessage(data);
    }
    catch(const std::exception&)
    {
    }
}

} /* namespace Lego */
