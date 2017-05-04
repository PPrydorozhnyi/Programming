#pragma once
#ifndef RESULTS_H
#define RESULTS_H

//#include <QWidget>
#include "activewindow.h"
#include "buttonwidget.h"

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

protected:
    void paintEvent(QPaintEvent *event) override;

//signals:
    //void created(const QString &value);
};

#endif // RESULTS_H
