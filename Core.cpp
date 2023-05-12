//
// Created by Никита on 12.05.2023.
//

#include "Core.h"

Core::Core(BaseComponent *interface, BaseComponent *game) : interface_(interface), game_(game) {
    this->interface_->set_mediator(this);
    this->game_->set_mediator(this);
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

void BaseComponent::set_mediator(Core *core) {
    this->core_ = core;
}

BaseComponent::BaseComponent(Core *core) : core_(core) {}