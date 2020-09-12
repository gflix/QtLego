#ifndef FORMS_GENERICCHILDDIALOG_HPP_
#define FORMS_GENERICCHILDDIALOG_HPP_

#include <QtCore/QList>
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

typedef QList<GenericChildDialog*> ChildDialogs;

} /* namespace Lego */

#endif /* FORMS_GENERICCHILDDIALOG_HPP_ */
