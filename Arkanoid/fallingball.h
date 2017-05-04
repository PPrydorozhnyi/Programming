#pragma once
#ifndef FALLINGBALL_H
#define FALLINGBALL_H

#include <QGraphicsEllipseItem>
#include <QPixmap>

class FallingBall : public QGraphicsEllipseItem
{
public:
    FallingBall(int x);

    // QGraphicsItem interface
public:
    void advance(int phase);
private:
    int yspeed = 2;
};

#endif // FALLINGBALL_H
