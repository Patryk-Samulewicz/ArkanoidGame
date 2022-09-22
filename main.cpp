#include "Game.h"
#include <QApplication>

using namespace std;

extern Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game *game = new Game();



    game->w.show();

    return a.exec();
}
