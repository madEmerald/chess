//
// Created by Никита on 12.05.2023.
//

#include "Core.h"

Core::Core(MainWindow *interface, Game *game) : interface_(interface), game_(game) {
    this->interface_->setCore(this);
    this->game_->setCore(this);
}

State Core::getCurrentState() {
    return this->game_->getCurrentState();
}

Color Core::getCurrentColor() {
    return this->game_->getCurrentColor();
}

std::set<Coords> Core::getAvailableMoves(Coords c) {
    return this->game_->getAvailableMoves(c);
}

bool Core::makeMove(Coords from, Coords to) {
    return this->game_->makeMove(from, to);
}

bool Core::getPawnPromoting(PieceType& pieceType) {
    std::string s;
    this->interface_->choosePawnPromoting(s);
    if (s == "B") {
        pieceType = PieceType::Bishop;
    } else if (s == "Kn") {
        pieceType = PieceType::Knight;
    } else if (s == "R") {
        pieceType = PieceType::Rook;
    } else if (s == "Q") {
        pieceType = PieceType::Queen;
    }

    return s == "";
}
