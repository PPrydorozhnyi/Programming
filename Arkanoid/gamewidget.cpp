#include "gamewidget.h"
#include "ui_gamewidget.h"
#include <QPainter>
#include <QGraphicsView>

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);

    this->resize(860,660);
    this->setFixedSize(860,660);

    timer = new QTimer(this);

    m_weidth = 125;
    counter = 0;

    connect(timer, SIGNAL (timeout() ),
            this, SLOT (onTimeOut()));
    timer->start(500);

    scene = new QGraphicsScene(100, 200, 600, 200);
    ui->graphicsView->resize(600,130);
    ui->graphicsView->setBackgroundBrush(QBrush(QPixmap(":/MyRes/fon2.jpg")));
    ui->graphicsView->setSceneRect(0,0,550,120);
    ui->graphicsView->setScene(scene);


    animationTimer = new QTimer(this);
    // change frame
    connect (animationTimer, SIGNAL(timeout()),
             scene,  SLOT(advance()));
            // 60 fps
    animationTimer->start(1000/60);

    generatorTimer = new QTimer(this);
    // generate balls
    connect(generatorTimer, SIGNAL(timeout()),
            this, SLOT(onGenerate()));
    generatorTimer->start(1000);

}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::onTimeOut()
{

    QLabel *label1 = new QLabel(this);
    //mylist.push_back(label1);
    //label->setText();
    label1->setPixmap(QPixmap(":/MyRes/22.png"));
    //label1->setText(QString::number(50000));
    label1->setGeometry(m_weidth, 450, 100, 100);

    m_weidth +=100;

    //label1->setText(QString::number(counter));

    label1->show();


    if (m_weidth > 625) {
        timer->stop();
        delete timer;

        //QString str = "Files successfully uploaded";
        QFont f( "Arial", 20, QFont::Bold);

        QLabel *label2 = new QLabel(this);
        //mylist.push_back(label2);
        label2->setText("<font color='white'>Files successfully uploaded</font>");
        label2->setFont(f);
        label2->setGeometry(250, 450, 400, 100);
        label2->show();
        //emit stopLoad();

    }


    //ui->label->setPixmap(QPixmap(":/MyRes/line_t_sinii.jpg").scaledToHeight(100));
    //ui->label->setGeometry(200, 200, 100, 100);
}

void GameWidget::onGenerate()
{
    scene->addItem(new FallingBall(scene->sceneRect().width()));
}

void GameWidget::paintEvent(QPaintEvent *) {

    QRectF source(0.0, 0.0, 860, 660);
    QImage image(":/MyRes/arkanoid-ii.jpg");

    QPainter painter(this);
    painter.drawImage(source,image);
}

/*void GameWidget::deleteLabels() {
    for (std::list<QLabel*>::iterator it=mylist.begin(); it != mylist.end(); ++it)
        delete *it;
}*/
