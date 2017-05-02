#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

//#include <QObject>
#include <QPushButton>
#include "activewindow.h"

class CustomButton : public QPushButton
{
    Q_OBJECT
public:
    CustomButton(QWidget* parent = 0, ActiveWindow* current = 0);
signals:
    void onChoose(ActiveWindow& );

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *) override;
private:
    ActiveWindow* current;
};

#endif // CUSTOMBUTTON_H
