#ifndef FORMS_ATTACHEDIORGBLIGHT_HPP_
#define FORMS_ATTACHEDIORGBLIGHT_HPP_

#include <forms/GenericChildDialog.hpp>
#include <models/lists/RgbLightColorList.hpp>

namespace Ui {
    class AttachedIoRgbLight;
}

namespace Lego
{

class AttachedIoRgbLight: public GenericChildDialog
{
    Q_OBJECT

public:
    explicit AttachedIoRgbLight(QWidget* parent = nullptr);
    virtual ~AttachedIoRgbLight();

public slots:
    void messageReceived(const QByteArray& data);
    void rgbLightColorChanged(int index);

protected:

private:
    Ui::AttachedIoRgbLight* m_ui;
    RgbLightColorList m_rgbLightColorList;

    void fixupUi(void);
};

} /* namespace Lego */

#endif /* FORMS_ATTACHEDIORGBLIGHT_HPP_ */
