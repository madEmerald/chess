#include "BaseComponent.h"

void BaseComponent::setCore(Core *core) {
    this->core_ = core;
}

BaseComponent::BaseComponent(Core *core) : core_(core) {}
