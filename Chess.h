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
protected:
    PieceType type_;
    Color color_;
    bool moved_;
    explicit Piece(Color);
    void setMoved(bool);
public:
    PieceType getType();
    Color getColor();
    [[nodiscard]] bool isMoved() const;

    virtual Piece* clone() = 0;
    virtual bool canMove(Coords) = 0;
    virtual bool makeMove(Coords, Board) = 0;
    virtual bool makeMove(Coords, Board, std::string &) = 0;
};

class Rook : private Piece {
public:
    explicit Rook(Color);
    Rook* clone() override;
    virtual bool canMove(Coords);
    virtual bool makeMove(Coords, Board);
    virtual bool makeMove(Coords, Board, std::string &);
};

class Pawn : private Piece {
public:
    explicit Pawn(Color);
    Pawn* clone() override;
    virtual bool canMove(Coords);
    virtual bool makeMove(Coords, Board);
    virtual bool makeMove(Coords, Board, std::string &);
};

class Knight : private Piece {
public:
    explicit Knight(Color);
    Knight* clone() override;
    virtual bool canMove(Coords);
    virtual bool makeMove(Coords, Board);
    virtual bool makeMove(Coords, Board, std::string &);
};

class Bishop : private Piece {
public:
    explicit Bishop(Color);
    Bishop* clone() override;
    virtual bool canMove(Coords);
    virtual bool makeMove(Coords, Board);
    virtual bool makeMove(Coords, Board, std::string &);
};

class Queen : private Piece {
public:
    explicit Queen(Color);
    Queen* clone() override;
    virtual bool canMove(Coords);
    virtual bool makeMove(Coords, Board);
    virtual bool makeMove(Coords, Board, std::string &);
};

class King : private Piece {
public:
    explicit King(Color);
    King* clone() override;
    virtual bool canMove(Coords);
    virtual bool makeMove(Coords, Board);
    virtual bool makeMove(Coords, Board, std::string &);
};

class Cell {
private:
    Piece* piece;
public:
    Cell();
    Piece* getPiece();
    void setPiece(Piece*);
    Cell clone();
};

class Board {
private:
    Cell cells_[8][8];
    Coords enPassant_;
    Coords whiteKingCoords_;
    Coords blackKingCoords_;
    Board(Cell (&cells)[8][8], Coords, Coords, Coords);
public:
    Board();
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
