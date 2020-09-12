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

} /* namespace Lego */
