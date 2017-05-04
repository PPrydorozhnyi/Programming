#include "brick.h"
#include <QDebug>

Brick::Brick(int x, int y)
{
    m_image.load(":/MyRes/brick.png");
    m_rect = m_image.rect();

    //his exactly position on the widget
    m_rect.translate(x, y);

    m_destroyed = false;
}

Brick::~Brick() {
    qDebug() << "Brick destroyed";
}

QRect Brick::getRect() {

    return m_rect;

}

void Brick::setRect(QRect rect) {
    m_rect = rect;
}

QImage & Brick::getImage() {

    return m_image;

}

bool Brick::isDestroyed() {

    return m_destroyed;

}


void Brick::setDestroyed(bool destroyed) {

    m_destroyed = destroyed;
}
