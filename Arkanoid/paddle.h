#pragma once
#ifndef PADDLE_H
#define PADDLE_H

#include <QImage>
#include <QRect>


class Paddle
{
public:
    Paddle();
    ~Paddle();

    void resetState();
    void move();
    void setDeltaX(int);
    QRect getRect();
    QImage &getImage();

private:
    QImage m_image;
    QRect m_rect;
    int dx;
    static const int INITIAL_X = 200;
    static const int INITIAL_Y = 360;
};

#endif // PADDLE_H
