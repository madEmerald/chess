//
// Created by Никита on 12.05.2023.
//

#ifndef CHESS_CORE_H
#define CHESS_CORE_H

#include <string>
#include <set>
#include "Chess.h"

using Cell = std::pair<int, int>;

class Token {
public:
    Token(Cell, std::string);
    Cell getPosition();
    std::string getType();
protected:
    Cell position_;
    std::string type_;
};

class BaseComponent;

class Core {
private:
    BaseComponent *interface_;
    BaseComponent *game_;
public:
    Core(BaseComponent *, BaseComponent *);

    State getCurrentState();

    Color getCurrentColor();

    void newGame();

    std::set<Cell> getAvailableMoves(Cell);

    bool makeTurn(Cell, Cell);
};

class BaseComponent {
protected:
    Core *core_;

public:
    explicit BaseComponent(Core *core = nullptr);

    void setCore(Core *core);
};

#endif //CHESS_CORE_H
