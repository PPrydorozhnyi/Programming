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
    ButtonWidget *buttonUp;
    ButtonWidget *buttonDown;

private:
    Ui::Results *ui;

    QPen pen;
    QColor background;
    int resultsWidth;
    int resultsHeight;
    int w;
    int currentPos;
    int toPos;
    int textWidth;
    QFont *font;
    QFont *fontR;
    QList<int> *list;
    QFile *file;
    QString stringBuffer;
    QTextStream *in;
    QFontMetrics *fontM1;
    LogLabel *label;

    //QFontMetrics *fontM;

    void drawTable(QPainter *);
    void drawScore(QPainter *);
    void readScore();

protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
    void onUp(bool);
    void onDown(bool);

//signals:
    //void created(const QString &value);
};

#endif // RESULTS_H
