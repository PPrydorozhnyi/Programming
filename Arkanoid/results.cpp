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
    button->setGeometry(795, 305, 60, 50 );

    pen = QPen( Qt::white, 4 );
    background = QColor(128, 0, 255);

    resultsWidth = 780;
    resultsHeight = 594;
    w = width();

    font = new QFont("Courier", 20, QFont::DemiBold);
    fontR = new QFont("Courier", 40, QFont::DemiBold);

    list = new QList<QString>();

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
    if (file)
        file->close();
}

void Results::paintEvent(QPaintEvent *)
{
    QRectF source(0.0, 0.0, 860, 660);
    QImage image(":/MyRes/results.jpg");

    QPainter painter(this);
    painter.drawImage(source,image);

    drawTable(&painter);
    readScore();
    //label->setText(list->back());
    qDebug() << list->count();
}

void Results::drawTable(QPainter *painter) {

    painter->setPen( pen );
    painter->drawRoundedRect(QRect (10, 56, resultsWidth, resultsHeight), 15, 15);

    int deltaHeight = resultsHeight / 11;

    for (int i = 0; i < 10; ++i)
        painter->drawLine(10, 110 + i * deltaHeight, 790, 110 + i * deltaHeight);
    painter->drawLine(10 + resultsWidth / 3, 56, 10 + resultsWidth / 3, 56 + resultsHeight);

    QFontMetrics fontM1(*font);

    painter->setFont(*font);

    int textWidth = fontM1.width("Number");
    painter->drawText(10 + resultsWidth / 6 -textWidth / 2, 90, "Number");

    textWidth = fontM1.width("Score");
    painter->drawText(10 + 2 * resultsWidth / 3 -textWidth / 2, 90, "Score");

    QFontMetrics fontM(*fontR);
    textWidth = fontM.width("RESULTS");

    painter->setFont(*fontR);

    painter->translate(w / 2, 40);
    painter->drawText(-textWidth / 2, 0, "RESULTS");

}

void Results::readScore() {

    if (file) {

      while (!in->atEnd())
         {
            list->append(in->readLine() );
         }

    }

}
