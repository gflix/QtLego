#ifndef WIDGETS_GENERALINFORMATION_HPP_
#define WIDGETS_GENERALINFORMATION_HPP_

#include <QtWidgets/QGroupBox>

namespace Ui {
    class GeneralInformation;
}

namespace Lego
{

class GeneralInformation: public QGroupBox
{
    Q_OBJECT

public:
    explicit GeneralInformation(QWidget* parent = nullptr);
    virtual ~GeneralInformation();

public slots:
    void messageReceived(const QByteArray& data);

protected:

private:
    Ui::GeneralInformation* m_ui;

};

} /* namespace Lego */

#endif /* WIDGETS_GENERALINFORMATION_HPP_ */
