#pragma once
#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <iostream>
#include <QGraphicsScene>
#include <fallingball.h>

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();
//signals:
   // void stopLoad();

private:
    Ui::GameWidget *ui;
    int m_weidth;
    int counter;
    QTimer *timer;
    //std::list<QLabel *> mylist;

    //void deleteLabels();
    QGraphicsScene *scene;
    QTimer *animationTimer;
    QTimer *generatorTimer;


private slots:
    void onTimeOut();
    void onGenerate();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // GAMEWIDGET_H
