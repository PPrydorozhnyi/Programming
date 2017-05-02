#include "playing.h"
#include "ui_playing.h"

Playing::Playing(QWidget *parent) :
    ActiveWindow(parent),
    ui(new Ui::Playing)
{
    ui->setupUi(this);
    resize(860,660);
    setFixedSize(860,660);

    button = new ButtonWidget(this,  QStringLiteral ("Menu"));
    button->setGeometry(700, 285, 60, 50 );
}


Playing::~Playing()
{
    onDelete();
    delete ui;
}

void Playing::paintEvent(QPaintEvent *)
{
    QRectF source(0.0, 0.0, 860, 660);
    QImage image(":/MyRes/playing.png");

    QPainter painter(this);
    painter.drawImage(source,image);
}
