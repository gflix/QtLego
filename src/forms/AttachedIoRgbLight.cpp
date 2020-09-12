#include <QtCore/QDebug>
#include <forms/AttachedIoRgbLight.hpp>
#include <protocols/GenericLeMessage.hpp>
#include <protocols/RgbLightColor.hpp>
#include "ui_AttachedIoRgbLight.h"

namespace Lego
{

AttachedIoRgbLight::AttachedIoRgbLight(QWidget* parent):
    GenericChildDialog(parent),
    m_ui(new Ui::AttachedIoRgbLight),
    m_rgbLightColorList(getRgbLightColors(), this)
{
    m_ui->setupUi(this);
    fixupUi();
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

void AttachedIoRgbLight::rgbLightColorChanged(int index)
{
    // TODO: use encoder instead of hard coded message
    auto data = QByteArray::fromHex("08008132105100");
    data.append(static_cast<uint8_t>(m_rgbLightColorList.get(index)));

    emit sendMessage(data);
}

void AttachedIoRgbLight::fixupUi(void)
{
    m_ui->comboRgbLight->setModel(&m_rgbLightColorList);
    m_ui->comboRgbLight->setCurrentIndex(-1);
    connect(
        m_ui->comboRgbLight, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        this, &AttachedIoRgbLight::rgbLightColorChanged);
}

} /* namespace Lego */
