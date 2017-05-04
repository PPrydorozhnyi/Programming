#pragma once
#ifndef BALL_H
#define BALL_H

#include <QImage>
#include <QRect>


class Ball
{
public:
    Ball();
    ~Ball();

    void resetState();
    void autoMove();
    void setX(int);
    void setY(int);
    int getX();
    int getY();
    QRect getRect();
    QImage &getImage();

private:

    int m_x;
    int m_y;
    QImage m_image;
    QRect m_rect;


    static const int INITIAL_X = 230;
    static const int INITIAL_Y = 355;
    static const int RIGHT_EDGE = 300;

};

#endif // BALL_H
