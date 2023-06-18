#include <iostream>
#include <utility>
#include "skill.h"
#include "monster.h"

Skill::Skill(const std::string& type) : skillType(type) {

}

std::string Skill::getSkillType() const {
    return skillType;
}

void Skill::chooseSkill(Monster* monster) {
    if (skillType == "fireball") {
        FireMonster* fireMonster = dynamic_cast<FireMonster*>(monster);
        if (fireMonster != nullptr) {
            fireMonster->increaseDamage(50);
            fireMonster->decreaseMana(20);
            std::cout << ">> SKILL ACTIVATED!  " << monster->getName() << " increased its damage by 50 using Fireball.\n";
        } else {
            monster->decreaseHealth(20);
            monster->decreaseMana(20);
            std::cout << ">> DEBUFF ACTIVATED!  " << monster->getName() << " tried to use Fireball and immolated themselves! Taks 20 damage.\n";
        }
    } else if (skillType == "waterfall") {
        WaterMonster* waterMonster = dynamic_cast<WaterMonster*>(monster);
        if (waterMonster != nullptr) {
            waterMonster->increaseHealth(20);
            waterMonster->decreaseMana(20);
            std::cout << ">> SKILL ACTIVATED!  " << monster->getName() << " increased its health by 20 using Waterfall.\n";
        } else {
            monster->decreaseHealth(20);
            monster->decreaseMana(20);
            std::cout << ">> DEBUFF ACTIVATED! " << monster->getName() << " slips into a puddle and decreases its health by 20 using Waterfall.\n";
        }
    } else if (skillType == "bigrock") {
        RockMonster* rockMonster = dynamic_cast<RockMonster*>(monster);
        if (rockMonster != nullptr) {
            rockMonster->increaseHealth(100);
            rockMonster->decreaseMana(20);
            std::cout << ">> SKILL ACTIVATED!  " << monster->getName() << " increased its health by 100 using Big Rock.\n";
        } else {
            monster->decreaseHealth(100);
            monster->decreaseMana(20);
            std::cout << ">> DEBUFF ACTIVATED! " << monster->getName() << " is crushed by a Big Rock.\n";
        }
    } else if (skillType == "keepstill") {
        GrassMonster* grassMonster = dynamic_cast<GrassMonster*>(monster);
        if (grassMonster != nullptr) {
            grassMonster->increaseDefense(100);
            grassMonster->decreaseMana(20);
            std::cout << ">> SKILL ACTIVATED!  " << monster->getName() << " crawls into fetal position using Keep Still and increases defence by 100!.\n";
        } else {
            std::cout << ">> SKILL NOT APPLICABLE!  " << monster->getName() << " cannot use the Keep Still skill.\n";
        }
    } else if (skillType == "manavoid") {
        if (monster->getTarget() != nullptr) {
            monster->getTarget()->decreaseMana(50);
            std::cout << ">> SKILL ACTIVATED!  " << monster->getName() << " drained 50 mana from " << monster->getTarget()->getName() << " using Mana Void.\n";
        } else {
            std::cout << ">> SKILL NOT APPLICABLE!  " << monster->getName() << " does not have a target to use the Mana Void skill.\n";
        }
    } else {
        std::cout << ">> UNKNOWN SKILL!  " << monster->getName() << " cannot use an unknown skill.\n";
    }
}


// Function to generate a random skill for the computer
Skill* generateRandomSkill() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 4);  // Updated range from 0 to 4

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
        case 4:
            randomSkill = new Skill("manavoid");
            break;
    }

    return randomSkill;
}

