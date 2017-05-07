#include "paddle.h"
#include <QDebug>

Paddle::Paddle()
{
    dx = 0;
    m_image.load(":/MyRes/paddle.png");

    //Returns the enclosing rectangle (0, 0, width(), height()) of the image.
    //m_rect = m_image.rect();
    m_rect = QRect(0, 0, 96, 22);
    resetState();
}

Paddle::~Paddle() {
    qDebug() << "Paddle deleted";
}

void Paddle::setDeltaX(int x) {

    if (x < 0 && m_rect.x() <= 0)
        dx = 0;
    else if (x > 0 && (m_rect.x() + m_rect.width()) >= 860)
        dx = 0;
    else
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
