#include <iostream>
#include <utility>
#include "skill.h"
#include "monster.h"

Skill::Skill(const std::string &type) : skillType(type) {

}

std::string Skill::getSkillType() const {
    return skillType;
}

void Skill::chooseSkill(Monster *monster) {
    if (skillType == "fireball") {
        auto *fireMonster = dynamic_cast<FireMonster *>(monster);
        if (fireMonster != nullptr) {
            fireMonster->increaseDamage(50);
            fireMonster->decreaseMana(20);
            std::cout << ">> SKILL ACTIVATED!  " << monster->getName()
                      << " increased its damage by 50 using Fireball.\n";
        } else {
            monster->decreaseHealth(20);
            monster->decreaseMana(20);
            std::cout << ">> DEBUFF ACTIVATED!  " << monster->getName()
                      << " tried to use Fireball and blew itself up! Takes 20 damage.\n";
        }
    } else if (skillType == "waterfall") {
        auto *waterMonster = dynamic_cast<WaterMonster *>(monster);
        if (waterMonster != nullptr) {
            waterMonster->increaseHealth(20);
            waterMonster->decreaseMana(20);
            std::cout << ">> SKILL ACTIVATED!  " << monster->getName()
                      << " increased its health by 20 using Waterfall.\n";
        } else {
            monster->decreaseHealth(20);
            monster->decreaseMana(20);
            std::cout << ">> DEBUFF ACTIVATED! " << monster->getName()
                      << " slips into a puddle and decreases its health by 20 using Waterfall.\n";
        }
    } else if (skillType == "bigrock") {
        auto *rockMonster = dynamic_cast<RockMonster *>(monster);
        if (rockMonster != nullptr) {
            rockMonster->increaseHealth(100);
            rockMonster->decreaseMana(20);
            std::cout << ">> SKILL ACTIVATED!  " << monster->getName()
                      << " increased its health by 100 using Big Rock.\n";
        } else {
            monster->decreaseHealth(20);
            monster->decreaseMana(20);
            std::cout << ">> DEBUFF ACTIVATED! " << monster->getName()
                      << " is crushed by a Big antimage. Takes 20 damage.\n";
        }
    } else if (skillType == "keepstill") {
        auto *grassMonster = dynamic_cast<GrassMonster *>(monster);
        if (grassMonster != nullptr) {
            grassMonster->increaseDefense(100);
            grassMonster->decreaseMana(20);
            std::cout << ">> SKILL ACTIVATED!  " << monster->getName()
                      << " curls into fetal position using Keep Still and increases defense by 100!.\n";
        } else {
            std::cout << ">> SKILL NOT APPLICABLE!  " << monster->getName()
                      << " Keeps Still and gets an arrow to the knee. 20 damage.\n";
        }
    } else if (skillType == "manavoid") {
        auto *poisonMonster = dynamic_cast<PoisonMonster *>(monster);
        if (poisonMonster != nullptr) {
            Monster* target = monster->getTarget();
            if (target != nullptr) {
                target->decreaseMana(50);
                std::cout << ">> SKILL ACTIVATED! " << monster->getName() << " drained 50 mana from " << target->getName() << " using Mana Void.\n";
            } else {
                monster->decreaseMana(20);
                monster->decreaseHealth(20);
                std::cout << ">> DEBUFFaaaa ACTIVATED! " << monster->getName() << " takes 20 damage using Mana Void.\n";
            }
        } else {
            monster->decreaseMana(20);
            monster->decreaseHealth(20);
            std::cout << ">> DEBUFF ACTIVATED! " << monster->getName()
                      << " tried to use Mana Void and took 20 damage and decreased its mana by 20.\n";
        } 
    } else if (skillType == "praisesun") {
        auto *antimageMonster = dynamic_cast<AntimageMonster *>(monster);
        if (antimageMonster != nullptr) {
            antimageMonster->increaseHealth(50);
            antimageMonster->decreaseMana(50);
            std::cout << ">> SKILL ACTIVATED!  " << monster->getName()
                      << " praises the sun and heals for 50!\n";
        } else {
            monster->decreaseHealth(50);
            monster->decreaseMana(20);
            std::cout << ">> DEBUFF ACTIVATED! " << monster->getName()
                      << " is punished by the sun. Takes 50 damage.\n";
        }
    }
    else {
        
        std::cout << ">> UNKNOWN SKILL! " << monster->getName() << " cannot use an unknown skill.\n";
    } 
}
std::string Skill::getName() const {
    return skillType;
}


// Function to generate a random skill for the computer
Skill *generateRandomSkill() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 5);

    int skillIndex = dis(gen);
    Skill *randomSkill = nullptr;

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
        case 5:
            randomSkill = new Skill("praisesun");
            break;
    }
    std::cout << "Computer used: " << randomSkill->getName() << std::endl;
    return randomSkill;
}
