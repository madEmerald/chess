#include "mainwindow.h"
#include "Chess.h"
#include "Core.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Game game;
    Core core(&w, &game);
    w.showInfo();

    w.show();

    return a.exec();
}
