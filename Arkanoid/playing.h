#ifndef PLAYING_H
#define PLAYING_H

//#include <QWidget>
#include "activewindow.h"
#include "buttonwidget.h"

namespace Ui {
class Playing;
}

class Playing : public ActiveWindow
{
    Q_OBJECT

public:
    explicit Playing(QWidget *parent = 0);
    ~Playing();
    ButtonWidget *button;

private:
    Ui::Playing *ui;

protected:
    void paintEvent(QPaintEvent *event) override;

//signals:
    //void created(const QString &value);
};

#endif // PLAYING_H
