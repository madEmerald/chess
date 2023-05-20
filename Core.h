//
// Created by Никита on 12.05.2023.
//

#ifndef CHESS_CORE_H
#define CHESS_CORE_H

#include <string>
#include <set>
#include "Chess.h"
#include "mainwindow.h"

class BaseComponent;

class Core {
private:
    MainWindow *interface_;
    Game *game_;
public:
    Core(MainWindow *, Game *);

    State getCurrentState();

    Color getCurrentColor();

    std::set<Coords> getAvailableMoves(Coords);

    bool makeMove(Coords, Coords);

    bool getPawnPromoting(PieceType&);
};

#endif //CHESS_CORE_H
