#include "paddle.h"
#include <QDebug>

Paddle::Paddle()
{
    dx = 0;
    m_image.load(":/MyRes/paddle.png");

    //Returns the enclosing rectangle (0, 0, width(), height()) of the image.
    m_rect = m_image.rect();
    resetState();
}

Paddle::~Paddle() {
    qDebug() << "Paddle deleted";
}

void Paddle::setDeltaX(int x) {
    dx = x;
}

void Paddle::move() {

    int x = m_rect.x() + dx;
    int y = m_rect.y();

    //Moves the rectangle, leaving the top-left corner at the given position (x, y).
    m_rect.moveTo(x, y);

}

void Paddle::resetState() {

    m_rect.moveTo(INITIAL_X, INITIAL_Y);

}

QRect Paddle::getRect() {
    return m_rect;
}

QImage & Paddle::getImage() {
    return m_image;
}
