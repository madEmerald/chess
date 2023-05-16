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
