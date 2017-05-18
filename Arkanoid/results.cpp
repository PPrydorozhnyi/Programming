#include "results.h"
#include "ui_results.h"
#include <QDebug>

Results::Results(QWidget *parent) :
    ActiveWindow(parent),
    ui(new Ui::Results)
{
    ui->setupUi(this);
    resize(860,660);
    setFixedSize(860,660);

    button = new ButtonWidget(this,  QStringLiteral ("Menu"));
    buttonUp = new ButtonWidget(this,  QStringLiteral ("UP"));
    buttonDown = new ButtonWidget(this,  QStringLiteral ("DOWN"));
    button->setBackground(QColor(168, 137, 5));

    pen = QPen( Qt::white, 4 );
    background = QColor(128, 0, 255);

    resultsWidth = 780;
    resultsHeight = 594;
    currentPos = 0;
    toPos = 10;
    button->setGeometry(795, 328, 60, 50 );
    buttonUp->setGeometry(795, 56, 60, 50 );
    buttonDown->setGeometry(795, 6 + resultsHeight, 60, 50 );
    w = width();

    buttonUp->setBackground(QColor(168, 137, 5));
    buttonDown->setBackground(QColor(168, 137, 5));

    font = new QFont("Courier", 20, QFont::DemiBold);
    QFont buttonFont("Courier", 14, QFont::DemiBold);
    fontM1 = new QFontMetrics(*font);
    fontR = new QFont("Courier", 40, QFont::DemiBold);

    button->setFont(buttonFont);
    buttonUp->setFont(buttonFont);
    buttonDown->setFont(buttonFont);

    connect(buttonUp, SIGNAL(clicked(bool)), this, SLOT(onUp(bool)));
    connect(buttonDown, SIGNAL(clicked(bool)), this, SLOT(onDown(bool)));

    list = new QList<int>();

    file = new QFile();
    file->setFileName("score.txt");

    if (!file->open(QIODevice::ReadOnly |QIODevice::Text) )
        qDebug()<< "can't open file for read score";

    in = new QTextStream(file);

    label = new LogLabel(this);
}

Results::~Results()
{
    onDelete();
    delete ui;
    list->clear();
    delete list;
    delete in;
    delete fontM1;
    delete font;
    if (file)
        file->close();
}

void Results::paintEvent(QPaintEvent *)
{
    QRectF source(0.0, 0.0, 860, 660);
    QImage image(":/MyRes/turquoise.jpg");

    QPainter painter(this);
    painter.drawImage(source,image);

    readScore();
    drawScore(&painter);
    drawTable(&painter);
    //label->setText(*list->back());
    //qDebug() << list->back();
    //qDebug() << 0;

}

void Results::drawTable(QPainter *painter) {

    painter->setPen( pen );
    painter->drawRoundedRect(QRect (10, 56, resultsWidth, resultsHeight), 15, 15);

    int deltaHeight = resultsHeight / 11;

    for (int i = 0; i < 10; ++i)
        painter->drawLine(10, 110 + i * deltaHeight, 790, 110 + i * deltaHeight);
    painter->drawLine(10 + resultsWidth / 3, 56, 10 + resultsWidth / 3, 56 + resultsHeight);

    //QFontMetrics fontM1(*font);

    painter->setFont(*font);

    textWidth = fontM1->width("Number");
    painter->drawText(10 + resultsWidth / 6 -textWidth / 2, 90, "Number");

    textWidth = fontM1->width("Score");
    painter->drawText(10 + 2 * resultsWidth / 3 -textWidth / 2, 90, "Score");

    QFontMetrics fontM(*fontR);
    textWidth = fontM.width("RESULTS");

    painter->setFont(*fontR);

    painter->translate(w / 2, 40);
    painter->drawText(-textWidth / 2, 0, "RESULTS");

}

void Results::drawScore(QPainter *painter) {

    painter->setPen(pen);
    painter->setFont(*font);

    //list->count() < currentPos + 10 ? toPos = list->count() : toPos = currentPos + 10;


    for (int i = currentPos , j = 0; i < toPos; ++i, ++j) {

        textWidth = fontM1->width(QString::number(currentPos + 1));
        //qDebug() << fontM1->height();
        painter->drawText(10 + resultsWidth / 6 -textWidth / 2, 145 + 54 * j, QString::number(i + 1));
        painter->drawText(10 + 2 * resultsWidth / 3 -textWidth / 2, 145 + 54 * j, QString::number(list->at(i)));

    }

}

void Results::readScore() {

    if (file) {

      while (!in->atEnd())
         {
            list->append(in->readLine().toInt() );
         }

    }

}

void Results::onUp(bool) {

    if (0 == currentPos) {

    } else if (0 > currentPos - 10) {

        currentPos = 0;
        toPos = 10;

    } else {

        currentPos = toPos - 20;
        toPos = toPos - 10;

    }
    qDebug() << toPos;
    update();

}

void Results::onDown(bool) {

    if (list->count() == toPos) {

    } else if (list->count() < toPos + 10) {

        currentPos = toPos;
        toPos = list->count();

    } else {

        currentPos = toPos;
        toPos = toPos + 10;

    }
    qDebug() << toPos;
    update();

}
