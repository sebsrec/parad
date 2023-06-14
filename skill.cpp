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
            std::cout << ">> SKILL ACTIVATED! Monster " << monster->getName() << " increased its damage by 50 using Fireball.\n";
        } else if (dynamic_cast<WaterMonster*>(monster) != nullptr) {
            monster->decreaseDamage(-5);
            std::cout << ">> SKILL ACTIVATED! Monster " << monster->getName() << " decreased its damage by 5 using Fireball against a Water Monster.\n";
        } else {
            std::cout << ">> SKILL NOT APPLICABLE! Monster " << monster->getName() << " cannot use the Fireball skill.\n";
        }
    } else if (skillType == "waterfall") {
        // Handle logic for "waterfall" skill
        if (dynamic_cast<WaterMonster*>(monster) != nullptr) {
            monster->increaseHealth(100);
            std::cout << ">> SKILL ACTIVATED! Monster " << monster->getName() << " increased its health by 100 using Waterfall.\n";
        } else {
            monster->decreaseHealth(10);
            std::cout << ">> SKILL ACTIVATED! Monster " << monster->getName() << " decreased its health by 10 using Waterfall.\n";
        }
    } else if (skillType == "bigrock") {
        // Handle logic for "bigrock" skill
        if (dynamic_cast<RockMonster*>(monster) != nullptr ||
            dynamic_cast<FireMonster*>(monster) != nullptr ||
            dynamic_cast<PoisonMonster*>(monster) != nullptr) {
            monster->increaseHealth(100);
            std::cout << ">> SKILL ACTIVATED! Monster " << monster->getName() << " increased its health by 100 using Big Rock.\n";
        } else {
            std::cout << ">> SKILL NOT APPLICABLE! Monster " << monster->getName() << " cannot use the Big Rock skill.\n";
        }
    } else if (skillType == "keepstill") {
        // Handle logic for "keepstill" skill
        if (dynamic_cast<FireMonster*>(monster) != nullptr ||
            dynamic_cast<GrassMonster*>(monster) != nullptr ||
            dynamic_cast<WaterMonster*>(monster) != nullptr ||
            dynamic_cast<PoisonMonster*>(monster) != nullptr) {
            monster->decreaseDefense(100);
            std::cout << ">> SKILL ACTIVATED! Monster " << monster->getName() << " set its defense power to 0 using Keep Still.\n";
        } else {
            std::cout << ">> SKILL NOT APPLICABLE! Monster " << monster->getName() << " cannot use the Keep Still skill.\n";
        }
    } else {
        std::cout << ">> UNKNOWN SKILL! Monster " << monster->getName() << " cannot use an unknown skill.\n";
    }
}
