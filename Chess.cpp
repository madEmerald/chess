//
// Created by Никита on 12.05.2023.
//

#include <algorithm>
#include "Chess.h"

Color Game::getCurrentColor() {
    return Color::Black;
}

State Game::getCurrentState() {
    return State::Common;
}

void Game::newGame() {

}

std::set<Coords> Game::getAvailableMoves(Coords c) {
    std::set<Coords> availableMoves;
    std::copy_if(this->allPossibleMoves.begin(), this->allPossibleMoves.end(),
                 std::back_inserter(availableMoves), [c](const Move &x) { return x.first == c; });
    return availableMoves;
}

Cell Game::getCell(Coords c) {
    return this->board.getCell(c);
}

bool Game::isLongCastlingPossible() {
    int x = this->getCurrentColor() == Color::Write ? 0 : 7;

    Piece* king = this->getCell({x, 0}).getPiece();
    Piece* rook = this->getCell({x, 4}).getPiece();

    if (king == nullptr || rook == nullptr) {
        return false;
    }

    if (king->getType != PieceType::King || rook->getType != PieceType::Rook)
        return false;

    if (king->getColor != this->getCurrentColor() || rook->getColor != this->getCurrentColor())
        return false;

    if (king->isMoved() || rook->isMoved())
        return false;

    if (this->getCell({x, 1}).getPiece() != nullptr || this->getCell({x, 1}).getPiece()
        || this->getCell({x, 1}).getPiece())
        return false;

    if (this->isUnderAttack({x, 4}) || this->isUnderAttack({x, 4}))
        return false;

    return true;

}

bool Game::makeMove(Coords, Coords) {
    return false;
}

bool Game::isUnderAttack(Coords c) {
    return this->board.isUnderAttack(c, this->getCurrentColor());
}


Piece *Cell::getPiece() {
    return nullptr;
}

bool Piece::isMoved() {
    return false;
}

Cell Board::getCell(Coords) {
    return Cell();
}

bool Board::isUnderAttack(Coords, Color) {
    return false;
}
