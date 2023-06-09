#include "item.h"

Item::Item(const std::string& name, int bonusDamage)
        : name(name), bonusDamage(bonusDamage), item(nullptr) {}

Item::~Item() = default;

std::string Item::getName() const {
    return name;
}

int Item::getBonusDamage() const {
    return bonusDamage;
}

void Item::setItem(Item* newItem) {
    item = newItem;
}