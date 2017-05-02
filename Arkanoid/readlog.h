#ifndef READLOG_H
#define READLOG_H

#include "activewindow.h"
#include <QLabel>
#include <QFile>
#include "buttonwidget.h"
#include "loglabel.h"

namespace Ui {
class ReadLog;
}

class ReadLog : public ActiveWindow
{
    Q_OBJECT

public:
    explicit ReadLog(QWidget *parent = 0, QString fileName = "test.txt");
    ~ReadLog();
    void run() override;
    ButtonWidget *buttonToMenu;
    QLabel *label;
    LogLabel *logLabel;

private:
    Ui::ReadLog *ui;
    QFile *file;
    int delta;
    int yDown, yUp, x;

    ButtonWidget *buttonUp;
    ButtonWidget *buttonDown;

public slots:
    void scrollDown(bool);
    void scrollUp(bool);


    //QWidget interface
protected:
   void paintEvent(QPaintEvent *event) override;
};

#endif // READLOG_H
