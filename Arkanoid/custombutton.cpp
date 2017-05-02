#include "custombutton.h"

CustomButton::CustomButton(QWidget* parent, ActiveWindow* current) :
    QPushButton(parent),
    current(current)
{

}

void CustomButton::mousePressEvent(QMouseEvent *)
{
    emit onChoose(*current);
}
