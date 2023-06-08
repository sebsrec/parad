#include "monster.h"
#include <iostream>

Monster::Monster(const std::string& name, int level, int healthPoints, int attackPower, int defense)
        : name(name), level (level), healthPoints(healthPoints), attackPower(attackPower), defensePower(defense) {}

Monster::~Monster() = default;

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
    int damage = 2 * getLevel() + getAttackPower() - target->getDefensePower() ;
   // std::cout << "Damage: " <<  2 * getLevel() << "+" << getAttackPower() << "-" << target->getDefensePower() << "=" << damage << "\n";

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

FireMonster::FireMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower)
        : Monster(name, level, healthPoints, attackPower, defensePower) {}

FireMonster::~FireMonster() {}

void FireMonster::attack(Monster* target) {
    Monster::attack(target);
    // Additional logic for FireMonster attack
}

WaterMonster::WaterMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower)
        : Monster(name, level, healthPoints, attackPower, defensePower) {}

WaterMonster::~WaterMonster() {}

void WaterMonster::attack(Monster* target) {
    Monster::attack(target);
    // Additional logic for WaterMonster attack
}



GrassMonster::GrassMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower)
        : Monster(name, level, healthPoints, attackPower, defensePower) {}

GrassMonster::~GrassMonster() {}

void GrassMonster::attack(Monster* target) {
    Monster::attack(target);
    // Additional logic for GrassMonster attack
}
