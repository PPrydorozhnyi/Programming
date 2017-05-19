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
#include <QDebug>

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
    int lastCount;
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

    template<class T>
    void quickSort (QList<T> *listt, int left, int right) {
        int i = left, j = right;
            T pivot = listt->at(left + (right - left) / 2);
            //qDebug() << pivot;

            // partition
            while (i <= j) {
                while (listt->at(i) > pivot)
                i++;
                while (listt->at(j) < pivot)
                j--;
                if (i <= j) {
                    //tmp = list->at(i);
                    listt->swap(i, j);
                    //qDebug() << "swap";
                    i++;
                    j--;
                }
            };

            // recursion
            if (left < j)
            quickSort(listt, left, j);
            if (i < right)
            quickSort(listt, i, right);
    }


protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
    void onUp(bool);
    void onDown(bool);


};

#endif // RESULTS_H
