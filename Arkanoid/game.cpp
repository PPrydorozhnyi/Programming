#include "game.h"
//#include <QSlider>
#include <QTimer>

Game::Game()
{
    m_widget = new MainWidget();
}


Game& Game::Instance()
{
    static Game theSingleInstance;
    return theSingleInstance;
}

void Game::run() {
    startGame = true;

    m_widget->show();
    m_widget->running();

    endGame = true;
}

