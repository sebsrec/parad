#include "monster.h"
#include <iostream>

Monster::Monster(const std::string& name, int level)
        : name(name), level(level), healthPoints(100), attackPower(10), defensePower(10) {}

Monster::~Monster() {}

std::string Monster::getName() const {
    return name;
}

int Monster::getLevel() const {
    return level;
}

int Monster::getHealthPoints() const {
    return healthPoints;
}

int Monster::getAttackPower() const {
    return attackPower;
}

int Monster::getDefensePower() const {
    return defensePower;
}

void Monster::attack(Monster* target) {
    int damage = attackPower - target->getDefensePower();
    if (damage > 0) {
        target->takeDamage(damage);
        std::cout << name << " attacked " << target->getName() << " for " << damage << " damage.\n";
    } else {
        std::cout << name << "'s attack was ineffective against " << target->getName() << ".\n";
    }
}

void Monster::takeDamage(int amount) {
    healthPoints -= amount;
    if (healthPoints < 0) {
        healthPoints = 0;
    }
}

FireMonster::FireMonster(const std::string& name, int level)
        : Monster(name, level) {}

FireMonster::~FireMonster() {}

void FireMonster::attack(Monster* target) {
    Monster::attack(target);
    // Additional logic for FireMonster attack
}

WaterMonster::WaterMonster(const std::string& name, int level)
        : Monster(name, level) {}

WaterMonster::~WaterMonster() {}

void WaterMonster::attack(Monster* target) {
    Monster::attack(target);
    // Additional logic for WaterMonster attack
}

GrassMonster::GrassMonster(const std::string& name, int level)
        : Monster(name, level) {}

GrassMonster::~GrassMonster() {}

void GrassMonster::attack(Monster* target) {
    Monster::attack(target);
    // Additional logic for GrassMonster attack
}
