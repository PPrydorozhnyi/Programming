#pragma once
#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

#include <QWidget>
#include <QPen>

namespace Ui {
class ButtonWidget;
}

class ButtonWidget : public QWidget
{
    Q_OBJECT

    static QString nullstr;

public:
    explicit ButtonWidget(QWidget *parent = nullptr, const QString &string = nullstr, QRectF *source = nullptr, QImage *image = nullptr);
    ~ButtonWidget();

    void setPen(QPen pen);
    void setBackground(QColor color);
    void setIconPos(QPoint point, QSize size);

private:
    Ui::ButtonWidget *ui;
    QRectF source;
    QImage image;
    QString string;
    QColor background;
    QPen pen;
    QPoint startPoint;
    QPoint iconPoint;
    QSize iconSize;

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);

signals:
    void clicked(bool);

};

#endif // BUTTONWIDGET_H
