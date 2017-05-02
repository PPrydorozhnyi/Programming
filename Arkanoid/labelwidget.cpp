#include "labelwidget.h"
#include "ui_labelwidget.h"
#include <QPainter>


QString LabelWidget::nullstr = QString ();


LabelWidget::LabelWidget(QWidget *parent, const QString &string, QRectF *source) :
    QWidget(parent),
    ui(new Ui::LabelWidget)
{
    ui->setupUi(this);
    this->string = string;

    if (!source)
        this->source = QRectF(10, 10 , width() / 2, height() / 2);
    else
        this->source = *source;
}

LabelWidget::~LabelWidget()
{
    delete ui;
}

void LabelWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawText(source, string);
}
