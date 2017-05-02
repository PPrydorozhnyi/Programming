#include "gamewidget.h"
#include <QApplication>
#include <game.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*GameWidget w;
    w.show();*/

    Game& game = Game::Instance();
    game.run();

    return a.exec();
}
