#pragma once
#ifndef BRICK_H
#define BRICK_H

#include <QImage>
#include <QRect>


class Brick
{
public:
    Brick(int, int);
    ~Brick();

    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    void setRect(QRect);
    QImage &getImage();

private:
    QImage m_image;
    QRect m_rect;
    bool m_destroyed;
};

#endif // BRICK_H
