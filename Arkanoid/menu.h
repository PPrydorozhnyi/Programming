#ifndef MENU_H
#define MENU_H

//#include <QWidget>
//#include "playing.h"
//#include "results.h"
//#include "custombutton.h"
//#include <QPushButton>
#include "activewindow.h"
#include <QLabel>
#include <iostream>
#include "buttonwidget.h"
#include "labelwidget.h"

namespace Ui {
class Menu;
}

class Menu : public ActiveWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0/*,Playing *playing = 0, Results *results = 0*/);
    ~Menu();
    //CustomButton* button1;
    ButtonWidget *button11;
    ButtonWidget *button12;
    ButtonWidget *button13;
    ButtonWidget *buttonForLog;

    void run() override;

private:
    Ui::Menu *ui;
    QLabel *label2;
    LabelWidget *label;
    int counter;
    std::string s[5];
    QFont *f;
    QTimer *timer;
    //Playing *playing;
    //Results *results;
protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
    void changeColor();

};

#endif // MENU_H
