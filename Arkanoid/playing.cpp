#include "playing.h"
#include "ui_playing.h"

Playing::Playing(QWidget *parent) :
    ActiveWindow(parent),
    ui(new Ui::Playing)
{
    ui->setupUi(this);
    resize(860,660);
    setFixedSize(860,660);

    //button = new ButtonWidget(this,  QStringLiteral ("Menu"));
    //button->setGeometry(700, 285, 60, 50 );

    setFocusPolicy(Qt::ClickFocus);
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

    QPainter painter1(this);
    painter1.drawImage(source,image);


}

void Playing::timerEvent(QTimerEvent * event)
{
    Q_UNUSED(event)
}

void Playing::keyPressEvent(QKeyEvent * event)
{
    Q_UNUSED(event)
}
