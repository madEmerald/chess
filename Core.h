//
// Created by Никита on 12.05.2023.
//

#ifndef CHESS_CORE_H
#define CHESS_CORE_H

#include <string>
#include <set>
#include "Chess.h"

class BaseComponent;
class Core {
private:
    BaseComponent *interface_;
    BaseComponent *board_;
    BaseComponent *game_;
public:
    Core(BaseComponent*, BaseComponent*);
    State getCurrentState();
    Color getCurrentColor();
    void newGame();
    std::set<cell> getAvailableMoves(cell);
    bool makeTurn(cell, cell);
};

class BaseComponent {
protected:
    Core *core_;

public:
    explicit BaseComponent(Core *core = nullptr);
    void set_mediator(Core *core);
};

#endif //CHESS_CORE_H
