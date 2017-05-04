#include "readlog.h"
#include "ui_readlog.h"

#include <QDebug>
#include <QPainter>
#include <QPaintEvent>

ReadLog::ReadLog(QWidget *parent, QString fileName) :
    ActiveWindow(parent),
    ui(new Ui::ReadLog)
{
    ui->setupUi(this);
    resize(860,660);
    setFixedSize(860,660);

    file = new QFile();
    file->setFileName(fileName);
    yDown = 600;
    yUp = 20;
    delta = 20;
    x = 700;

    if (!file->open(QIODevice::ReadOnly |QIODevice::Text) )
        //qDebug()<< "can't open file for read log";

    QSize size(50, 50);
    //QImage icon1 (":/MyRes/double_down.png");
    //QImage icon2 (":/MyRes/double_up1600.png");

    buttonDown = new ButtonWidget(this, QStringLiteral ("Down"));
    //buttonDown->setIcon(QIcon(":/MyRes/double_down.png"));
    //buttonDown->setIconSize(size);

    buttonUp = new ButtonWidget(this,  QStringLiteral ("UP"));
    //buttonUp->setIcon(QIcon(":/MyRes/double_up1600.png"));
    //buttonUp->setIconSize(size);

    buttonToMenu = new ButtonWidget(this,  QStringLiteral ("Menu"));
    //buttonDown->setIcon(QIcon(":/MyRes/double_down.png"));
    //buttonDown->setIconSize(size);

    buttonDown->setGeometry(x, yDown, 60, 50);
    buttonUp->setGeometry(x, yUp, 60, 50);
    buttonToMenu->setGeometry(x, 285, 60, 50 );

    logLabel = new LogLabel (this);
    logLabel->setGeometry(0, 0, x, height ());

    connect(buttonDown, SIGNAL (clicked(bool)), this, SLOT(scrollDown(bool)));
    connect(buttonUp, SIGNAL (clicked(bool)), this, SLOT(scrollUp(bool)));

}

ReadLog::~ReadLog()
{
    delete ui;
    if (file)
        file->close();
}

void ReadLog::run()
{

    //label = new QLabel(this);

    //if (!file->open(QIODevice::ReadOnly |QIODevice::Text) ) {

        //qDebug()<< "can't open file for read log";
    //}

    //QTextStream in(file);

    //label->setText(in.readAll());
    //label->setText("dd");

    //if (file)
        //file->close();

    //label->show();

    //update();

    file->reset();
    QTextStream in (file);
    logLabel->setText(in.readAll ());
}

void ReadLog::scrollDown(bool)
{
    QRectF source;
    scroll(0, -delta);
    //y += delta - 10;
    buttonDown->setGeometry(x, yDown, 60, 50);
    buttonUp->setGeometry(x, yUp, 60, 50);
    buttonToMenu->setGeometry(x, 285, 60, 50 );
    //update();
}

void ReadLog::scrollUp(bool)
{
    scroll(0, delta);
    //y += delta - 10;
    buttonUp->setGeometry(x, yUp, 60, 50);
    buttonDown->setGeometry(x, yDown, 60, 50);
    buttonToMenu->setGeometry(x, 285, 60, 50 );
    //update();
}

void ReadLog::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event)
#if 0
    qDebug () << event->region ();
    QRectF source(0.0, 0.0, 860, 660);
    QPainter painter(this);

    QTextStream in(file);

    painter.drawText(source, QString(in.readAll()) );
#endif
}

