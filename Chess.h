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

class Board;
class Piece {
private:
    PieceType type;
    Color color;
    bool moved;
public:
    PieceType getType();
    Color getColor();
    bool isMoved();
    bool canMove(Coords);
    bool makeMove(Coords, Board);
    bool makeMove(Coords, Board, std::string &);
};

class Cell {
private:
    Piece* piece;
public:
    Piece* getPiece();
};

class Board {
private:
    Cell cells[8][8];
    Cell enPassant;
    Cell whiteKingCoords;
    Cell blackKingCoords;
public:
    Cell getCell(Coords);
    bool isLongCastlingPossible(Color);
    bool isShortCastlingPossible(Color);
    bool isUnderAttack(Coords, Color);
    Board clone();
    Coords getKingCoords(Color);
};

class Game : public BaseComponent {
private:
    Color currentColor;
    State currentState;
    std::set<Move> allPossibleMoves;
    Board board;
    void getAllPossibleMoves();
    void updateStatus();
public:
    Color getCurrentColor();
    State getCurrentState();
    void newGame();
    std::set<Coords> getAvailableMoves(Coords);
    bool makeMove(Move);
};

#endif //CHESS_CHESS_H
