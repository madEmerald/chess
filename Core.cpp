//
// Created by Никита on 12.05.2023.
//

#include "Core.h"

#include <utility>

Core::Core(BaseComponent *interface, BaseComponent *game) : interface_(interface), game_(game) {
    this->interface_->setCore(this);
    this->game_->setCore(this);
}

State Core::getCurrentState() {
    return State::Mate;
}

Color Core::getCurrentColor() {
    return Color::Black;
}

void Core::newGame() {
    printf("new game started yay!");
}

std::set<Cell> Core::getAvailableMoves(Cell c) {
    return {c};
}

bool Core::makeTurn(Cell, Cell) {
    return true;
}

void BaseComponent::setCore(Core *core) {
    this->core_ = core;
}

BaseComponent::BaseComponent(Core *core) : core_(core) {}

Token::Token(Cell position, std::string type) : position_(std::move(position)), type_(std::move(type)) {}

Cell Token::getPosition() {
    return this->position_;
}

std::string Token::getType() {
    return this->type_;
}
