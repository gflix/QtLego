#include <QtCore/QDebug>
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
    qInfo() << "GeneralInformation::messageReceived()";
}

} /* namespace Lego */
