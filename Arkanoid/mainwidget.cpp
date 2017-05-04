#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <iostream>
#include <QDebug>


MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    this->resize(860,660);
    this->setFixedSize(860,660);
    this->setWindowTitle(QString("Arkanoid"));
    isDebug = true;
    cont = new char[60];

     current = nullptr;
     m_menu = nullptr;
     m_playing = nullptr;
     m_results = nullptr;
     m_readLog = nullptr;

}

MainWidget::~MainWidget()
{
    delete[] cont;
    delete ui;
}

void MainWidget::running()
{
    fileName = "test.txt";
    logger = new Logger(this, fileName);
    //logger->write("Hello Qt");
    //m_gwidget = new GameWidget(this);
    //m_gwidget->show();
    QTimer::singleShot(1/*10000*/, this, SLOT(onLoadFinish()));
}

void MainWidget::onLoadFinish()
{
    //delete m_gwidget;

    logger->write("Load finished");

    onMenu(true);
    connect(m_menu->button[0], SIGNAL (clicked(bool)), this, SLOT (onSwap(bool)) );
    connect(m_menu->button[1], SIGNAL (clicked(bool)), this, SLOT (onResults(bool)) );
    connect(m_menu->button[2], SIGNAL (clicked(bool)), QApplication::instance(), SLOT (quit()) );
    connect(m_menu->button[3], SIGNAL (clicked(bool)), this, SLOT ( onShowLog(bool)));
}


/*void MainWidget::onSwap(ActiveWindow& recieved)
{
    if (!recieved)
    {
        m_playing = new Playing(this);
    }



    qDebug() << "eeeeee";

}*/

void MainWidget::onMenu(bool)
{
    if (!m_menu) {
        m_menu = new Menu(this);

        connect(m_menu, SIGNAL (forLogger(const QString &)), logger, SLOT (write(const QString &)) );
    }
    strategy(*m_menu);
    qDebug() << "menu";

}

void MainWidget::onSwap(bool)
{
    if (!m_playing) {
    m_playing = new Playing(this);
    connect(m_playing, SIGNAL (forLogger(const QString &)), logger, SLOT (write(const QString &)) );
    connect(m_playing, SIGNAL (clicked(bool)), this, SLOT (onMenu(bool)));
    }
    strategy(*m_playing);
    qDebug() << "playing";

}

void MainWidget::onResults(bool)
{
    if (!m_results) {
    m_results = new Results(this);
    connect(m_results, SIGNAL (forLogger(const QString &)), logger, SLOT (write(const QString &)) );
    connect(m_results->button, SIGNAL (clicked(bool)), this, SLOT (onMenu(bool)));
    }
    strategy(*m_results);
    qDebug() << "results";
}

void MainWidget::onShowLog(bool)
{
    if (!m_readLog) {
    m_readLog = new ReadLog(this, fileName);
    connect(m_readLog->buttonToMenu, SIGNAL (clicked(bool)), this, SLOT (onMenu(bool)));
}
    //m_readLog->showLog(logger->read());
    strategy(*m_readLog);
    qDebug() << "showLog";
}

void MainWidget::strategy(ActiveWindow &action)
{
    if (current) {
        current->hide();
        logger->write(strcat(strcpy(cont, "Hide " ), typeid(*current).name()) );
        //delete current;
    }

    action.run();
    current = &action;
    logger->write(strcat(strcpy(cont, "Curent widget is " ), typeid(*current).name()) );
    //action.resize(860,660);
    //action.setFixedSize(860,660);
    action.show();
}
