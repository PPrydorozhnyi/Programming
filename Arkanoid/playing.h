#pragma once
#ifndef PLAYING_H
#define PLAYING_H

//#include <QWidget>

#include "activewindow.h"
#include "buttonwidget.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"

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

    int m_x;
    int m_timerId;
    static const int AMOUNT_OF_BRICKS = 35;
    static const int DELAY = 10;
    static const int BOTTOM_EDGE = 700;
    Ball *ball;
    Paddle *paddle;
    Brick *bricks[AMOUNT_OF_BRICKS];

    bool m_gameOver;
    bool m_gameWon;
    bool m_gameStated;
    bool m_paused;

    void drawObjects(QPainter *);
    void onFinishGame(QPainter *, QString);
    void moveObjects();
    void pauseGame();
    void stopGame();
    void startGame();
    void flawlessVictory();
    void checkCollisions();

protected:
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *) override;
    void keyPressEvent(QKeyEvent *) override;
    void keyReleaseEvent(QKeyEvent *) override;

signals:
    void clicked(bool);

    // ActiveWindow interface
public:
    void run();
};

#endif // PLAYING_H
