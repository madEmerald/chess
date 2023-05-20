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
public:
    ~Piece();
    PieceType getType();
    Color getColor();
    void setMoved(bool);
    [[nodiscard]] bool isMoved() const;

    virtual Piece* clone() = 0;
    virtual bool canMove(Move, Board&) = 0;
    virtual bool makeMove(Move, Board&);
    virtual bool makeMove(Move, Board&, std::string &);
};

class Rook : private Piece {
public:
    explicit Rook(Color);
    Rook* clone() override;
    bool canMove(Move, Board&) override;
};

class Pawn : private Piece {
public:
    explicit Pawn(Color);
    Pawn* clone() override;
    bool canMove(Move, Board&) override;
    bool makeMove(Move, Board&) override;
    bool makeMove(Move, Board&, std::string &) override;
};

class Knight : private Piece {
public:
    explicit Knight(Color);
    Knight* clone() override;
    bool canMove(Move, Board&) override;
};

class Bishop : private Piece {
public:
    explicit Bishop(Color);
    Bishop* clone() override;
    bool canMove(Move, Board&) override;
};

class Queen : private Piece {
public:
    explicit Queen(Color);
    Queen* clone() override;
    bool canMove(Move, Board&) override;
};

class King : private Piece {
public:
    explicit King(Color);
    King* clone() override;
    bool canMove(Move, Board&) override;
    bool makeMove(Move, Board&) override;
    bool makeMove(Move, Board&, std::string &) override;
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
    void setKingCoords(Coords, Color);
    void setEnPassantCellCoords(Coords);
    Coords getKingCoords(Color);
    Coords getEnPassantCellCoords();
    virtual bool getPawnPromoting(PieceType&);
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
