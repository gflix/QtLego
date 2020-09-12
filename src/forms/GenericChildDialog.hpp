#ifndef FORMS_GENERICCHILDDIALOG_HPP_
#define FORMS_GENERICCHILDDIALOG_HPP_

#include <QtWidgets/QDialog>

namespace Lego
{

class GenericChildDialog: public QDialog
{
    Q_OBJECT

public:
    explicit GenericChildDialog(QWidget* parent = nullptr);
    virtual ~GenericChildDialog();

protected:

private:

};

} /* namespace Lego */

#endif /* FORMS_GENERICCHILDDIALOG_HPP_ */
