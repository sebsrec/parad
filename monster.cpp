#include "monster.h"
#include <iostream>
#include <random>
#include <utility>


Monster::Monster(std::string  name, int level, int healthPoints, int attackPower, int defense)
        : name(std::move(name)), level (level), healthPoints(healthPoints), attackPower(attackPower), defensePower(defense) {}

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
    int damage = 2 * getLevel() + getAttackPower() - target->getDefensePower() ; //Default attack damage

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

void Monster::reduceDefense(int amount) {
    defensePower -= amount;
    if (defensePower < 0) {
        defensePower = 0;
    }
}

double odds(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double chance = dis(gen);
    return chance;
}

FireMonster::FireMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower)
        : Monster(name, level, healthPoints, attackPower, defensePower) {}

FireMonster::~FireMonster() = default;

void FireMonster::attack(Monster* target) {
    // Call the base class's attack function
    Monster::attack(target);
    // critical strike 25% chance, 1.5x dmg
    double  chance= odds();

    if (chance <= 0.25) {
        int criticalDamage =   getLevel() + 1.5 * (getAttackPower());
        target->takeDamage(criticalDamage);
        std::cout << getName() << " lands a critical strike on " << target->getName() << " for " << criticalDamage << " damage!\n";
    }
}

WaterMonster::WaterMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower)
        : Monster(name, level, healthPoints, attackPower, defensePower) {}

WaterMonster::~WaterMonster() = default;

void WaterMonster::attack(Monster* target) {
    Monster::attack(target);
    // 30% chance Lifesteal

    double  chance= odds();
    if (chance <= 0.35) {
        int lifestealAmount= getAttackPower();
        takeDamage(-lifestealAmount);
        std::cout << getName() << " uses Lifesteal and heals for " << lifestealAmount << " HP!\n";

    }
}

GrassMonster::GrassMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower)
        : Monster(name, level, healthPoints, attackPower, defensePower) {}

GrassMonster::~GrassMonster() = default;

void GrassMonster::attack(Monster* target) {
    Monster::attack(target);
    // 70% chance Armor reduction

    double  chance = odds();
    if (chance <= 0.70) {
        int targetDefense = target->getDefensePower();
        target->reduceDefense(targetDefense);
        std::cout << getName() << " negates " << target->getName() << "'s armor!\n";
    }
}

RockMonster::RockMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower)
        : Monster(name, level, healthPoints, attackPower, defensePower) {}

RockMonster::~RockMonster() = default;

void RockMonster::attack(Monster* target) {
    Monster::attack(target);
    // 70% Damage Block

    double  chance = odds();
    if (chance <= 0.70) {
        takeDamage(0);
        std::cout << getName() << " blocks " << target->getName() << "'s attack!\n";
    }
}


