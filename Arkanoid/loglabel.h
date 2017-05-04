#pragma once
#ifndef LOGLABEL_H
#define LOGLABEL_H

#include <QWidget>

class LogLabel : public QWidget
{
    Q_OBJECT

    QString text;
    bool bounded;
public:
    explicit LogLabel(QWidget *parent = 0);

    void setText (const QString &text);
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *);
};

#endif // LOGLABEL_H
