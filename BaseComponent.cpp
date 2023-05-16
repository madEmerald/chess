#include "BaseComponent.h"

void BaseComponent::setCore(Core *core) {
    this->core_ = core;
}

BaseComponent::BaseComponent(Core *core) : core_(core) {}

Token::Token(Coords position, std::string type) : position_(std::move(position)), type_(std::move(type)) {}

Coords Token::getPosition() {
    return this->position_;
}

std::string Token::getType() {
    return this->type_;
}
