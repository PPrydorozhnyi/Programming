#include "fallingball.h"
#include <QBrush>
#define SIZE 60

// haven`t parent
FallingBall::FallingBall(int x) : QGraphicsEllipseItem(0)
{
    //QColor color = QColor(rand() % 255, rand() % 255, rand() % 255);
    // set kist`
    setBrush(QBrush(QPixmap(":/MyRes/aqua-ball-icon-2_65x65.png")));
    // zone for circle
    setRect(0, 0, SIZE, SIZE);
    // shift position
    setPos(rand() % (x - SIZE), 0);
}

// 2 times for 0 and 1
void FallingBall::advance(int phase)
{
    if (phase)
    {
        moveBy(0, yspeed);
    }
}
