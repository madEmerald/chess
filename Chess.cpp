//
// Created by Никита on 12.05.2023.
//

#include <algorithm>
#include <utility>
#include "Chess.h"

Color oppositeColor(Color c) {
    return c == Color::Write ? Color::Black : Color::Write;
}

Color Game::getCurrentColor() {
    return this->currentColor;
}

State Game::getCurrentState() {
    return this->currentState;
}

void Game::newGame() {

}

std::set<Coords> Game::getAvailableMoves(Coords c) {
    std::set<Coords> availableMoves;
    std::copy_if(this->allPossibleMoves.begin(), this->allPossibleMoves.end(),
                 std::back_inserter(availableMoves), [c](const Move &x) { return x.first == c; });
    return availableMoves;
}

bool Game::makeMove(Move m) {
    if (currentState == State::Mate || currentState == State::Stalemate)
        return false;

    if (this->allPossibleMoves.count(m)) {
        this->board.getCell(m.first).getPiece()->makeMove(m.second, this->board); //
        this->currentColor = oppositeColor(this->currentColor);
        this->updateStatus();

        return true;
    }
    return false;
}

void Game::getAllPossibleMoves() {
    this->allPossibleMoves.clear();

    for (int i = 0; i < 64; ++i) {
        for (int j = 0; j < 64; ++j) {
            if (i != j) {
                Coords c1 = {i / 8, i % 8};
                Coords c2 = {j / 8, j % 8};

                Board b = this->board.clone();
                Piece *piece = b.getCell(c1).getPiece();
                if (piece == nullptr || piece->getColor() != this->currentColor)
                    continue;

                if (piece->makeMove(c2, b))
                    if (!b.isUnderAttack(b.getKingCoords(this->currentColor), oppositeColor(this->currentColor)))
                        this->allPossibleMoves.insert({c1, c2});
            }
        }
    }
}

void Game::updateStatus() {
    this->getAllPossibleMoves();
    this->currentState = State::Common;

    if (this->board.isUnderAttack(this->board.getKingCoords(this->currentColor), this->currentColor))
        this->currentState = State::Check;

    if (this->allPossibleMoves.empty()) {
        if (this->currentState == State::Check)
            this->currentState = State::Mate;
        else
            this->currentState = State::Stalemate;
    }
}

bool Board::isLongCastlingPossible(Color c) {
    int x = c == Color::Write ? 0 : 7;

    Piece *king = this->getCell({x, 4}).getPiece();
    Piece *rook = this->getCell({x, 0}).getPiece();

    if (king == nullptr || rook == nullptr)
        return false;

    if (king->getType() != PieceType::King || rook->getType() != PieceType::Rook)
        return false;

    if (king->getColor() != c || rook->getColor() != c)
        return false;

    if (king->isMoved() || rook->isMoved())
        return false;

    if (this->getCell({x, 1}).getPiece() != nullptr || this->getCell({x, 2}).getPiece()
        || this->getCell({x, 3}).getPiece())
        return false;

    if (this->isUnderAttack({x, 4}, oppositeColor(c))
        || this->isUnderAttack({x, 2}, oppositeColor(c))
        || this->isUnderAttack({x, 3}, oppositeColor(c)))
        return false;

    return true;
}

bool Board::isShortCastlingPossible(Color c) {
    int x = c == Color::Write ? 0 : 7;

    Piece *king = this->getCell({x, 4}).getPiece();
    Piece *rook = this->getCell({x, 7}).getPiece();

    if (king == nullptr || rook == nullptr)
        return false;

    if (king->getType() != PieceType::King || rook->getType() != PieceType::Rook)
        return false;

    if (king->getColor() != c || rook->getColor() != c)
        return false;

    if (king->isMoved() || rook->isMoved())
        return false;

    if (this->getCell({x, 5}).getPiece() != nullptr || this->getCell({x, 6}).getPiece())
        return false;

    if (this->isUnderAttack({x, 4}, oppositeColor(c))
        || this->isUnderAttack({x, 5}, oppositeColor(c))
        || this->isUnderAttack({x, 6}, oppositeColor(c)))
        return false;

    return true;
}

bool Board::isUnderAttack(Coords coords, Color color) {
    for (int i = 0; i < 64; ++i) {
        Piece *attacker = this->cells_[i / 8][i % 8].getPiece();
        if (attacker != nullptr && attacker->getColor() != color && attacker->canMove(coords))
            return true;
    }
    return false;
}

Cell Board::getCell(Coords c) {
    return this->cells_[c.first][c.second];
}

Board::Board(Cell (&cells)[8][8], Coords enPassant, Coords whiteKingCoords, Coords blackKingCoords) :
        enPassant_(std::move(enPassant)), whiteKingCoords_(std::move(whiteKingCoords)),
        blackKingCoords_(std::move(blackKingCoords)) {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            this->cells_[i][j] = cells[i][j].clone();
}

Board Board::clone() {
    return {this->cells_, this->enPassant_,
            this->whiteKingCoords_, this->blackKingCoords_};
}

Coords Board::getKingCoords(Color c) {
    return c == Color::Write ? this->whiteKingCoords_ : this->blackKingCoords_;
}

Cell::Cell() {
    this->piece = nullptr;
}

Piece *Cell::getPiece() {
    return this->piece;
}

void Cell::setPiece(Piece *p) {
    this->piece = p;
}

Cell Cell::clone() {
    Cell cell;
    Piece p{*(this->piece)};
    cell.setPiece(&p);

    return cell;
}

bool Piece::isMoved() const {
    return this->moved;
}

bool Piece::makeMove(Coords, Board) {
    return false;
}

bool Piece::makeMove(Coords, Board, std::string &) {
    return false;
}

bool Piece::canMove(Coords) {
    return false;
}

PieceType Piece::getType() {
    return PieceType::King;
}

Color Piece::getColor() {
    return Color::Black;
}
