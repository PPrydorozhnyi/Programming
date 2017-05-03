#include "menu.h"
#include "ui_menu.h"

#include <QTimer>
#include <QMouseEvent>
#include <QDebug>

Menu::Menu(QWidget *parent) :
    ActiveWindow(parent),

    ui(new Ui::Menu)
{
    ui->setupUi(this);

    resize(860,660);
    setFixedSize(860,660);

    QPoint point(35, 35);
    QPoint iconP(330, 285);
    QPoint iconP1(350, 415);
    QPoint iconP2(380, 545);
    QPoint iconP3(670, 610);
    QSize size(30,30);
    QSize size1(200,200);
    n = 4;

    //QRectF source(point, size1);
    QRect sourceF(330, 250, 200, 100);
    QRect sourceF1(330, 380, 200, 100);
    QRect sourceF2(330, 510, 200, 100);
    QRect sourceF3(700, 600, 50, 50);
    //QRect sourceFF(point, size1);
    //QRectF source1(QPoint(70, 35), size1);
    QImage icon1 (":/MyRes/transparent.png");
    QImage icon2 (":/MyRes/14.png");
    QImage icon3 (":/MyRes/close-icon-17.png");

    int width = this->width();
    int height = this->height();

    button = new buttonFake*[n];

    button[0] = new buttonFake( &sourceF, &width, &height, QStringLiteral ("New Game"), this, &icon1);
    button[0]->setIconPos(iconP, size);

    button[1] = new buttonFake( &sourceF1, &width, &height, QStringLiteral ("Results"), this, &icon2);
    button[1]->setIconPos(iconP1, size);

    button[2] = new buttonFake( &sourceF2, &width, &height, QStringLiteral ("Quit"), this, &icon3);
    button[2]->setIconPos(iconP2, size);

    button[3] = new buttonFake( &sourceF3, &width, &height, QStringLiteral ("Log"), this);
    button[3]->setIconPos(iconP3, size);

    //button11 = new ButtonWidget(this, QStringLiteral ("New Game"), &source, &icon1 );
    //button12 = new ButtonWidget(this,  QStringLiteral ("Results"), &source, &icon2 );
    //button13 = new ButtonWidget(this,  QStringLiteral ("Quit"), &source1 , &icon3 );

    //buttonForLog = new ButtonWidget(this, QStringLiteral ("Log") );

    //QFont font ("Courier", 20, QFont::Bold);


    //button11->setFont(font);
    //button12->setFont(font);
    //button13->setFont(font);

    //button11->setGeometry(330, 250, 200, 100);
    //button11->setToolTip("Press to start a new game");
    //button11->setIconPos(iconP, size);

    //button12->setGeometry(330, 380, 200, 100);
    //button12->setToolTip("Press to watch your results");
    //button12->setIconPos(iconP, size);

    //button13->setGeometry(330, 510, 200, 100);
    //button13->setIconPos(iconP1, size);
    //button13->setToolTip("Press to end this session");

    //buttonForLog->setGeometry(700, 600, 50, 50);
    //buttonForLog->setToolTip("Read log");

    QRectF text(0, 0 , 400, 400);

    label = new LabelWidget(this, QStringLiteral ("MENU"), &text);
    f = new QFont( "Arial", 90, QFont::Bold);
    buttonFont = new QFont("Courier", 20, QFont::Bold);

    s[0] = "color: rgb(128, 0, 255)";
    s[1] = "color: rgb(255, 255, 0)";
    //s[2] = "color: rgb(173, 255, 47)";
    s[2] = "color: rgb(255, 0, 0)";
    s[3] = "color: rgb(0, 255, 0)";
    s[4] = "color: rgb(0, 255, 255)";

    timer = new QTimer(this);

    label->setFont(*f);
    label->setGeometry(250, 80, 400, 200);

}

Menu::~Menu()
{
    onDelete();
    delete ui;
}

void Menu::run()
{
    //emit forLogger("Load finised");
    emit forLogger("Menu executed");

    //QFont f( "Arial", 90, QFont::Bold);

    counter = 0;


    //label2 = new QLabel(this);

    connect(timer, SIGNAL(timeout()),
            this, SLOT(changeColor()));

    //label2->setText("MENU");
    label->setStyleSheet("color: rgb(128, 0, 255)");
    label->show();

    timer->start(2000);

}

void Menu::paintEvent(QPaintEvent *)
{

    //QBrush br( button[0]->background, Qt::SolidPattern );
    //br.setStyle(Qt::SolidPattern);

    //for (int i = 0; i < n; i++)
        //painterr[i] = new QPainter(this);

    QRect source(0, 0, 860, 660);
    QImage image(":/MyRes/bright-yellow-brick-wall-texture-with-vertical-bricks.jpg");

    QPainter painter(this);
    painter.drawImage(source,image);

    QPainter painter1(this);
    //painterr[0]->setBrush( QBrush( QColor(128, 0, 255) , Qt::SolidPattern) );

    for (int i = 0; i < n; i++) {
    painter1.setPen( button[i]->pen );
    painter1.setBrush( QBrush( button[i]->background , Qt::SolidPattern) );
    painter1.drawRoundedRect(QRectF (button[i]->source), 15, 15);
    painter1.drawImage(QRectF (button[i]->iconPoint, button[i]->iconSize),button[i]->image);

    //source.moveLeft(source.left() + 10);

    painter1.setFont(*buttonFont);
    painter1.drawText(QRectF (button[i]->iconPoint.x()+30, button[i]->iconPoint.y(), 200, 200), button[i]->string);
    }

}

void Menu::changeColor()
{
    label->setStyleSheet(s[counter].c_str());
    ++counter;
    if (counter == 5)
        counter = 0;
}

void Menu::mousePressEvent(QMouseEvent *event)
{
    for (int i = 0; i < n; i++) {
        if ( button[i]->contains(event->pos())&&event->button() == Qt::LeftButton )
        {
            //qDebug() << "Clicked";
            emit button[i]->clicked(true);

        }
    }

}
