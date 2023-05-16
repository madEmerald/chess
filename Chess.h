//
// Created by Никита on 12.05.2023.
//

#ifndef CHESS_CHESS_H
#define CHESS_CHESS_H

#include <utility>
#include <set>
#include "BaseComponent.h"


using Coords = std::pair<int, int>;
using Move = std::pair<Coords, Coords>;

class Piece {
private:
    PieceType type;
    Color color;
    bool moved;
public:
    PieceType getType;
    Color getColor;
    bool isMoved();
};

class Cell {
public:
    Piece* getPiece();
};

class Board {
private:
    Cell board[8][8];
public:
    Cell getCell(Coords);
    bool isUnderAttack(Coords, Color);
};

class Game : public BaseComponent {
private:
    Color currentColor;
    State currentState;
    std::set<Move> allPossibleMoves;
    bool isUnderAttack(Coords);
    Cell getCell(Coords);
    Board board;
public:
    Color getCurrentColor();
    State getCurrentState();
    void newGame();
    std::set<Coords> getAvailableMoves(Coords);
    bool makeMove(Coords, Coords);
};

#endif //CHESS_CHESS_H
