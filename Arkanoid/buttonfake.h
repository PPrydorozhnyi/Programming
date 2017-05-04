#pragma once
#ifndef BUTTONFAKE_H
#define BUTTONFAKE_H

#include <QObject>
#include <QRect>
#include <QPoint>
#include <QImage>
#include <QPen>
#include <QColor>

class buttonFake : public QObject
{

    static QString nullstr;
    Q_OBJECT

public:
    buttonFake(QRect *source, const int *width, const int *height, const QString &string = nullstr, QObject *parent = nullptr , QImage *image = nullptr );
    ~buttonFake();

    void setPen(QPen pen);
    void setBackground(QColor color);
    void setIconPos(QPoint point, QSize size);
    void paintEvent();
    //void click();

    bool contains(const QPoint &p);

//private:
    QRect source;
    QImage image;
    QString string;
    QColor background;
    QPen pen;
    QPoint startPoint;
    QPoint iconPoint;
    QSize iconSize;

    // QWidget interface

signals:
    void clicked(bool);
};

#endif // BUTTONFAKE_H
