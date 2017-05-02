#include "buttonwidget.h"
#include "ui_buttonwidget.h"

#include <QPainter>
#include <QDebug>


QString ButtonWidget::nullstr = QString ();

ButtonWidget::ButtonWidget(QWidget *parent, const QString &string, QRectF *source, QImage *image) :
    QWidget(parent),
    ui(new Ui::ButtonWidget)
{
    ui->setupUi(this);
    if (image)
        this->image = *image;
    if (!source)
        this->source = QRectF(10, 10 , width() / 2, height() / 2);
    else
        this->source = *source;
    this->string = string;
    pen = QPen( Qt::white, 4 );
    background = QColor(128, 0, 255);
    iconPoint = startPoint = QPoint(width() / 8, height() / 8 );
    iconSize = QSize(30, 30);
}

ButtonWidget::~ButtonWidget()
{
    delete ui;
}

void ButtonWidget::setPen(QPen pen)
{
    this->pen = pen;
}

void ButtonWidget::setBackground(QColor color)
{
    this->background = color;
}

void ButtonWidget::setIconPos(QPoint point, QSize size)
{
    this->iconPoint = point;
    this->iconSize = size;
}

void ButtonWidget::mousePressEvent(QMouseEvent *)
{
    emit clicked(true);
}

void ButtonWidget::paintEvent(QPaintEvent *)
{

    //QPainter p(this);
    //p.setBackground(QBrush( QColor(128, 0, 255) ));

    QPainter painter(this);
    painter.setPen( pen );
    painter.setBrush( QBrush( background ) );
    painter.drawRoundedRect(QRectF (QPointF (0, 0), size ()), 15, 15);
    painter.drawImage(QRectF (iconPoint, iconSize),image);

    //source.moveLeft(source.left() + 10);
    painter.drawText(source, string);
}
