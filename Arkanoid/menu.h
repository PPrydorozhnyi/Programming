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
#include "buttonfake.h"

namespace Ui {
class Menu;
}

class Menu : public ActiveWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();
    //CustomButton* button1;
    //buttonFake *button1;
    //buttonFake *button2;
    //buttonFake *button3;

    buttonFake **button;

    //ButtonWidget *button11;
    //ButtonWidget *button12;
    //ButtonWidget *button13;
    ButtonWidget *buttonForLog;

    void run() override;

private:
    Ui::Menu *ui;
    QLabel *label2;
    LabelWidget *label;
    int counter;
    std::string s[5];
    QFont *f, *buttonFont;
    QTimer *timer;
    int n;
    //QPainter **painterr;
    //Playing *playing;
    //Results *results;
protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
    void changeColor();


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // MENU_H
