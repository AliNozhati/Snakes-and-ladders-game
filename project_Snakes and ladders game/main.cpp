#include "mainwindow.h"

#include <QApplication>
#include <Structure.h>
#include <Function.h>

unsigned int IndexPlayers[5] = {0,0,0,0,0};
int CountPlayers = 0, Count = 0;
vector <Player> Myplayer;
vector <Player> showscore;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
