#ifndef ACTIVEWINDOW_H
#define ACTIVEWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QString>
#include <typeinfo>

namespace Ui {
class ActiveWindow;
}

class ActiveWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ActiveWindow(QWidget *parent = 0);
    virtual ~ActiveWindow();
    virtual void run();

private:
    Ui::ActiveWindow *ui;
signals:
    void forLogger(const QString &value);
protected:
    void onDelete();
};

#endif // ACTIVEWINDOW_H
