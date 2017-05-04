#pragma once
#ifndef PLAYING_H
#define PLAYING_H

//#include <QWidget>

#include "activewindow.h"
#include "buttonwidget.h"

#include <QPaintEvent>
#include <QTimerEvent>
#include <QKeyEvent>


namespace Ui {
class Playing;
}

class Playing : public ActiveWindow
{
    Q_OBJECT

public:
    explicit Playing(QWidget *parent = 0);
    ~Playing();
    ButtonWidget *button;

private:

    Ui::Playing *ui;

protected:
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *) override;
    void keyPressEvent(QKeyEvent *) override;

signals:
    void clicked(bool);
};

#endif // PLAYING_H
