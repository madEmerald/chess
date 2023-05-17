//
// Created by Никита on 12.05.2023.
//

#include <algorithm>
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
    if (this->allPossibleMoves.count(m)) {
        this->board.getCell(m.first).getPiece()->makeMove(m.second);
        this->currentColor = oppositeColor(this->currentColor);
        this->updateStatus();

        return true;
    }
    return false;
}

void Game::updateStatus() {

}

bool Board::isLongCastlingPossible(Color c) {
    int x = c == Color::Write ? 0 : 7;

    Piece *king = this->getCell({x, 4}).getPiece();
    Piece *rook = this->getCell({x, 0}).getPiece();

    if (king == nullptr || rook == nullptr)
        return false;

    if (king->getType != PieceType::King || rook->getType != PieceType::Rook)
        return false;

    if (king->getColor != c || rook->getColor != c)
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

    if (king->getType != PieceType::King || rook->getType != PieceType::Rook)
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

}


Cell Board::getCell(Coords c) {
    return this->cells[c.first][c.second];
}

Piece *Cell::getPiece() {
    return this->piece;
}

bool Piece::isMoved() {
    return this->moved;
}

bool Piece::makeMove(Coords) {
    return false;
}

