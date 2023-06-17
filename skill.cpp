#include <iostream>
#include <utility>
#include "skill.h"
#include "monster.h"

Skill::Skill(const std::string& type) : skillType(type) {}

std::string Skill::getSkillType() const {
    return skillType;
}

void Skill::chooseSkill(Monster* monster) {
    if (skillType == "fireball") {
        // Handle logic for "fireball" skill
        if (dynamic_cast<FireMonster*>(monster) != nullptr) {
            monster->increaseDamage(50);
            monster->decreaseMana(20);  // Decrease mana by 20
            std::cout << ">> SKILL ACTIVATED!  " << monster->getName() << " increased its damage by 50 using Fireball.\n";
        } else if (dynamic_cast<WaterMonster*>(monster) != nullptr) {
            monster->decreaseDamage(-20);
            monster->decreaseMana(20);  // Decrease mana by 20
            std::cout << ">> DEBUFF ACTIVATED!  " << monster->getName() << " decreased its damage by 20 using Fireball against a Water Monster.\n";
        } else {
            std::cout << ">> SKILL NOT APPLICABLE!  " << monster->getName() << " cannot use the Fireball skill.\n";
        }
    } else if (skillType == "waterfall") {
        // Handle logic for "waterfall" skill
        if (dynamic_cast<WaterMonster*>(monster) != nullptr) {
            monster->increaseHealth(100);
            monster->decreaseMana(20);  // Decrease mana by 20
            std::cout << ">> SKILL ACTIVATED!  " << monster->getName() << " increased its health by 100 using Waterfall.\n";
        } else {
            monster->decreaseHealth(100);
            monster->decreaseMana(20);  // Decrease mana by 20
            std::cout << ">> DEBUFF ACTIVATED! " << monster->getName() << " slips into a puddle and decreases its health by 100 using Waterfall.\n";
        }
    } else if (skillType == "bigrock") {
        // Handle logic for "bigrock" skill
        if (dynamic_cast<RockMonster*>(monster) != nullptr) {
            monster->increaseHealth(100);
            monster->decreaseMana(20);  // Decrease mana by 20
            std::cout << ">> SKILL ACTIVATED!  " << monster->getName() << " increased its health by 100 using Big Rock.\n";
        } else {
            monster->decreaseHealth(100);
            monster->decreaseMana(20);  // Decrease mana by 20
            std::cout << ">> DEBUFF ACTIVATED! " << monster->getName() << " is crushed by a Big Rock.\n";
        }
    } else if (skillType == "keepstill") {
        // Handle logic for "keepstill" skill
        if (dynamic_cast<GrassMonster*>(monster) != nullptr) {
            monster->decreaseDefense(100);
            monster->decreaseMana(20);  // Decrease mana by 20
            std::cout << ">> SKILL ACTIVATED!  " << monster->getName() << " set its defense power to 0 using Keep Still.\n";
        } else {
            std::cout << ">> SKILL NOT APPLICABLE!  " << monster->getName() << " cannot use the Keep Still skill.\n";
        }
    } else {
        std::cout << ">> UNKNOWN SKILL!  " << monster->getName() << " cannot use an unknown skill.\n";
    }
}

// Function to generate a random skill for the player
Skill* generateRandomSkill() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);

    int skillIndex = dis(gen);
    Skill* randomSkill = nullptr;

    switch (skillIndex) {
        case 0:
            randomSkill = new Skill("fireball");
            break;
        case 1:
            randomSkill = new Skill("waterfall");
            break;
        case 2:
            randomSkill = new Skill("bigrock");
            break;
        case 3:
            randomSkill = new Skill("keepstill");
            break;
    }

    return randomSkill;
}
