#include "results.h"
#include "ui_results.h"

Results::Results(QWidget *parent) :
    ActiveWindow(parent),
    ui(new Ui::Results)
{
    ui->setupUi(this);
    resize(860,660);
    setFixedSize(860,660);

    button = new ButtonWidget(this,  QStringLiteral ("Menu"));
    button->setGeometry(700, 285, 60, 50 );
}

Results::~Results()
{
    onDelete();
    delete ui;
}

void Results::paintEvent(QPaintEvent *)
{
    QRectF source(0.0, 0.0, 860, 660);
    QImage image(":/MyRes/results.jpg");

    QPainter painter(this);
    painter.drawImage(source,image);
}
