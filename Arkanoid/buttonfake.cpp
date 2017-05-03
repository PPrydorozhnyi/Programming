#include "buttonfake.h"

#include <QPainter>
#include <QDebug>


QString buttonFake::nullstr = QString ();

buttonFake::buttonFake( QRect *source, const int *width, const int *height, const QString &string, QObject *parent, QImage *image) :
QObject(parent)
{
    if (image)
        this->image = *image;
    if (!source)
        this->source = QRect(10, 10 , (int)(*width / 2), (int)(*height / 2));
    else
        this->source = *source;
    this->string = string;
    pen = QPen( Qt::white, 4 );
    background = QColor(128, 0, 255);
    iconPoint = startPoint = QPoint( (int)(*width / 8), (int)(*height / 8) );
    iconSize = QSize(30, 30);
}

buttonFake::~buttonFake()
{

}

void buttonFake::setPen(QPen pen)
{
    this->pen = pen;
}

void buttonFake::setBackground(QColor color)
{
    this->background = color;
}

void buttonFake::setIconPos(QPoint point, QSize size)
{
    this->iconPoint = point;
    this->iconSize = size;
}


void buttonFake::paintEvent()
{

    //QPainter p(this);
    //p.setBackground(QBrush( QColor(128, 0, 255) ));

    QPainter painter;
    painter.setPen( pen );
    painter.setBrush( QBrush( background ) );
    painter.drawRoundedRect(QRectF (QPointF (0, 0), source.size()), 15, 15);
    painter.drawImage(QRectF (iconPoint, iconSize),image);

    //source.moveLeft(source.left() + 10);
    painter.drawText(source, string);
}

/*void buttonFake::click()
{
    emit clicked(true);
}*/



bool buttonFake::contains(const QPoint &p)
{
            if (p.x() < source.x() || p.x() > source.x() + source.width() )
                return false;


            if (p.y() < source.y() || p.y() > source.y() + source.width())
                return false;

    return true;
}
