#include "item.h"

Item::Item(const std::string& name, int bonusDamage, int bonusDefense)
        : name(name), bonusDamage(bonusDamage), bonusDefense(bonusDefense), item(nullptr) {}

Item::~Item() = default;

std::string Item::getName() const {
    return name;
}

int Item::getBonusDamage() const {
    return bonusDamage;
}
int Item::getBonusDefense() const {
    return bonusDefense;
}

void Item::setItem(Item* newItem) {
    item = newItem;
}