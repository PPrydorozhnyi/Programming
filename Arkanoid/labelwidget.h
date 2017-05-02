#ifndef LABELWIDGET_H
#define LABELWIDGET_H

#include <QWidget>

namespace Ui {
class LabelWidget;
}

class LabelWidget : public QWidget
{
    Q_OBJECT

    static QString nullstr;

public:
    explicit LabelWidget(QWidget *parent = 0, const QString &string = nullstr, QRectF *source = nullptr );
    ~LabelWidget();

private:
    Ui::LabelWidget *ui;
    QString string;
    QRectF source;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // LABELWIDGET_H
