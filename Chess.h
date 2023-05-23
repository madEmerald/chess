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
};

class Rook : public Piece {
public:
    explicit Rook(Color);
    Rook* clone() override;
    bool canMove(Move, Board&) override;
};

class Pawn : public Piece {
public:
    explicit Pawn(Color);
    Pawn* clone() override;
    bool canMove(Move, Board&) override;
    bool makeMove(Move, Board&) override;
};

class Knight : public Piece {
public:
    explicit Knight(Color);
    Knight* clone() override;
    bool canMove(Move, Board&) override;
};

class Bishop : public Piece {
public:
    explicit Bishop(Color);
    Bishop* clone() override;
    bool canMove(Move, Board&) override;
};

class Queen : public Piece {
public:
    explicit Queen(Color);
    Queen* clone() override;
    bool canMove(Move, Board&) override;
};

class King : public Piece {
public:
    explicit King(Color);
    King* clone() override;
    bool canMove(Move, Board&) override;
    bool makeMove(Move, Board&) override;
};

class Cell {
private:
    Piece* piece;
public:
    Cell();
    ~Cell();
    Piece* getPiece();
    void setPiece(Piece*);
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
    virtual bool isLongCastlingPossible(Color);
    virtual bool isShortCastlingPossible(Color);
    virtual bool isUnderAttack(Coords, Color);
    virtual Board clone();
    virtual void setKingCoords(Coords, Color);
    virtual void setEnPassantCellCoords(Coords);
    virtual Coords getKingCoords(Color);
    virtual Coords getEnPassantCellCoords();
    virtual bool getPawnPromoting(PieceType&);
    virtual Cell *getCell(Coords c);
};

class Game : private Board, public BaseComponent {
private:
    Color currentColor;
    State currentState;
    std::set<Move> allPossibleMoves;
    Board *board;
    void findAllPossibleMoves();
    void updateStatus();
public:
    Game();
    Color getCurrentColor();
    State getCurrentState();
    std::set<Move> getAllPossibleMoves();
    bool makeMove(Move);

    Cell *getCell(Coords) override;
    bool isLongCastlingPossible(Color) override;
    bool isShortCastlingPossible(Color) override;
    bool isUnderAttack(Coords, Color) override;
    Board clone() override;
    void setKingCoords(Coords, Color) override;
    void setEnPassantCellCoords(Coords) override;
    Coords getKingCoords(Color) override;
    Coords getEnPassantCellCoords() override;
    bool getPawnPromoting(PieceType&) override;
};

#endif //CHESS_CHESS_H
