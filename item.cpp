#include "item.h"

Item::Item(const std::string& name, int bonusDamage, int bonusDefense, int bonusHealth, int bonusMana)
        : name(name), bonusDamage(bonusDamage), bonusDefense(bonusDefense), bonusHealth(bonusHealth), bonusMana(bonusMana),item(nullptr) {}

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

int Item::getBonusMana() const {
    return bonusMana;
}

void Item::setItem(Item* newItem) {//Don't delete! doesn't work if removed...
    item = newItem;
}