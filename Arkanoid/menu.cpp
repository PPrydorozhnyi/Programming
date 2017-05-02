#include "menu.h"
#include "ui_menu.h"

#include <QTimer>

Menu::Menu(QWidget *parent/*, Playing *playing, Results *results*/) :
    ActiveWindow(parent),
    //playing(playing),
    //results(results),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    resize(860,660);
    setFixedSize(860,660);

    //button1 = new CustomButton(this, playing);
    QPoint point(35, 35);
    QPoint iconP(0, 35);
    QPoint iconP1(30, 35);
    QSize size(30,30);
    QSize size1(200,200);

    QRectF source(point, size1);
    QRectF source1(QPoint(70, 35), size1);
    QImage icon1 (":/MyRes/transparent.png");
    QImage icon2 (":/MyRes/14.png");
    QImage icon3 (":/MyRes/close-icon-17.png");

    button11 = new ButtonWidget(this, QStringLiteral ("New Game"), &source, &icon1 );
    button12 = new ButtonWidget(this,  QStringLiteral ("Results"), &source, &icon2 );
    button13 = new ButtonWidget(this,  QStringLiteral ("Quit"), &source1 , &icon3 );
    //button11->setPen(QPen (Qt::black, 2));

    //button12 = new QPushButton("Results", this);

    //button13 = new QPushButton("Quit", this);

    buttonForLog = new ButtonWidget(this, QStringLiteral ("Log") );

    QFont font ("Courier", 20, QFont::Bold);
    //QPalette myPalette = button12->palette();
    //myPalette.setColor( button12->backgroundRole(), QColor(128, 0, 255) );

    //button12->setPalette( myPalette );
    //button13->setPalette( myPalette );

    button11->setFont(font);
    button12->setFont(font);
    button13->setFont(font);

    //button11->setFixedSize(200, 100);
    button11->setGeometry(330, 250, 200, 100);
    button11->setToolTip("Press to start a new game");
    button11->setIconPos(iconP, size);
    //button11->setIcon(icon1);

    //button12->setFixedSize(200, 100);
    button12->setGeometry(330, 380, 200, 100);
    button12->setToolTip("Press to watch your results");
    button12->setIconPos(iconP, size);
    //button12->setIcon(icon2);

    //button13->setFixedSize(200, 100);
    button13->setGeometry(330, 510, 200, 100);
    button13->setIconPos(iconP1, size);
    button13->setToolTip("Press to end this session");
    //button13->setIcon(icon3);

    buttonForLog->setGeometry(700, 600, 50, 50);
    buttonForLog->setToolTip("Read log");

    QRectF text(0, 0 , 400, 400);

    label = new LabelWidget(this, QStringLiteral ("MENU"), &text);
    f = new QFont( "Arial", 90, QFont::Bold);

    s[0] = "color: rgb(128, 0, 255)";
    s[1] = "color: rgb(255, 255, 0)";
    //s[2] = "color: rgb(173, 255, 47)";
    s[2] = "color: rgb(255, 0, 0)";
    s[3] = "color: rgb(0, 255, 0)";
    s[4] = "color: rgb(0, 255, 255)";

    timer = new QTimer(this);

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
    label->setFont(*f);
    label->setGeometry(250, 80, 400, 200);
    label->show();

    timer->start(2000);

}

void Menu::paintEvent(QPaintEvent *)
{
    QRectF source(0.0, 0.0, 860, 660);
    QImage image(":/MyRes/bright-yellow-brick-wall-texture-with-vertical-bricks.jpg");

    QPainter painter(this);
    painter.drawImage(source,image);
}

void Menu::changeColor()
{
    label->setStyleSheet(s[counter].c_str());
    ++counter;
    if (counter == 5)
        counter = 0;
}
