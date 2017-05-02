#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "gamewidget.h"
#include "menu.h"
#include "playing.h"
#include "results.h"
#include "logger.h"
#include "readlog.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void running();
private slots:
    void onLoadFinish();
    //void onSwap(ActiveWindow& recieved);
    void onSwap(bool);
    void onResults(bool);
    void onShowLog(bool);
    void onMenu(bool);


private:
    Ui::MainWidget *ui;

    GameWidget* m_gwidget;

    bool isDebug;
    QString fileName;
    char* cont;
    Logger *logger;

    Menu *m_menu;
    Playing *m_playing;
    Results *m_results;
    ReadLog *m_readLog;
    ActiveWindow *current;

    void strategy(ActiveWindow& action);
};

#endif // MAINWIDGET_H
