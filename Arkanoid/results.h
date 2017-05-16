#pragma once
#ifndef RESULTS_H
#define RESULTS_H

//#include <QWidget>
#include "activewindow.h"
#include "buttonwidget.h"
#include "loglabel.h"
#include <iostream>
#include <QFile>
#include <QTextStream>

namespace Ui {
class Results;
}

class Results : public ActiveWindow
{
    Q_OBJECT

public:
    explicit Results(QWidget *parent = 0);
    ~Results();
    ButtonWidget *button;

private:
    Ui::Results *ui;

    QPen pen;
    QColor background;
    int resultsWidth;
    int resultsHeight;
    int w;
    QFont *font;
    QFont *fontR;
    QList<QString> *list;
    QFile *file;
    QString stringBuffer;
    QTextStream *in;
    LogLabel *label;

    //QFontMetrics *fontM;

    void drawTable(QPainter *);
    void readScore();

protected:
    void paintEvent(QPaintEvent *event) override;

//signals:
    //void created(const QString &value);
};

#endif // RESULTS_H
