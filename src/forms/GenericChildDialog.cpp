#include <forms/GenericChildDialog.hpp>

namespace Lego
{

GenericChildDialog::GenericChildDialog(QWidget* parent):
    QDialog(parent, Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint)
{
}

GenericChildDialog::~GenericChildDialog()
{
}

void GenericChildDialog::messageReceived(const QByteArray& data)
{
}

} /* namespace Lego */
