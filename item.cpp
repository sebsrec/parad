#include "item.h"

Item::Item(const std::string& name, int bonusDamage, int bonusDefense, int bonusHealth)
        : name(name), bonusDamage(bonusDamage), bonusDefense(bonusDefense), bonusHealth(bonusHealth), item(nullptr) {}

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

int Item::getBonusHealth() const {
    return bonusHealth;
}

void Item::setItem(Item* newItem) {
    item = newItem;
}