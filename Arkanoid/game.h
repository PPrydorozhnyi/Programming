#ifndef GAME_H
#define GAME_H

#include "mainwidget.h"
//#include <QProgressBar>
//#include <QHBoxLayout>

class Game
{

public:
    static Game& Instance();

    void run();

private:
    Game();
    Game(const Game& root);
    Game& operator=(const Game&);
    MainWidget* m_widget;

    bool startGame;
    bool endGame;
};

#endif // GAME_H
