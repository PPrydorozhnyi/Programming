#include "ball.h"
#include "QDebug"

Ball::Ball()
{
    m_x = 1;
    m_y = -1;

    m_image.load(":/MyRes/ball.png");

    m_rect = QRect(0,0,30,30);
    //m_rect = m_image.rect();
    resetState();
}

Ball::~Ball() {

    qDebug() << "Ball deleted";
}

void Ball::autoMove() {

    m_rect.translate(m_x, m_y);

    if (m_rect.x() == 0) {

        m_x = 1;

    }

    if (m_rect.right() == RIGHT_EDGE) {

        m_x = -1;

    }

    if (m_rect.y() == 0) {

        m_y = 1;

    }
}


void Ball::resetState() {

    m_rect.moveTo(INITIAL_X, INITIAL_Y);

}

void Ball::setX(int x) {

    m_x = x;

}

int Ball::getX() {

    return m_x;

}

void Ball::setY(int y) {

    m_y = y;

}

int Ball::getY() {

    return m_y;

}

QRect Ball::getRect() {

    return m_rect;

}


QImage & Ball::getImage() {

    return m_image;

}
