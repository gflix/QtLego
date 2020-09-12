#ifndef FORMS_GENERICCHILDDIALOG_HPP_
#define FORMS_GENERICCHILDDIALOG_HPP_

#include <QtCore/QMap>
#include <QtWidgets/QDialog>

namespace Lego
{

class GenericChildDialog: public QDialog
{
    Q_OBJECT

public:
    explicit GenericChildDialog(QWidget* parent = nullptr);
    virtual ~GenericChildDialog();

public slots:
    void messageReceived(const QByteArray& data);

signals:
    void sendMessage(const QByteArray& data);

protected:

private:

};

typedef QMap<int, GenericChildDialog*> AttachedIoChildDialogs;

} /* namespace Lego */

#endif /* FORMS_GENERICCHILDDIALOG_HPP_ */
