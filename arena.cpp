#include <iostream>
#include "arena.h"

Arena::Arena(const std::string& type) : arenaType(type) {}

std::string Arena::getArenaType() const {
    return arenaType;
}

void Arena::enterArena(Monster* monster) {
    // special boost or debuff based on the arena type
    if (arenaType == "hell") {
        if (dynamic_cast<FireMonster*>(monster) != nullptr) {
            monster->increaseHealth(50);
            std::cout << ">> ARENA BONUS! " << monster->getName()
                      << " descended into the depths of HELL and gained 50 extra health.\n";
        } else {
            monster->decreaseHealth(50);
            std::cout << ">> ARENA DEBUFF! " << monster->getName()
                      << " burns in the depths of HELL and loses 50 health.\n";
        }
    } else if (arenaType == "ocean") {
        if (dynamic_cast<WaterMonster*>(monster) != nullptr) {
            monster->increaseHealth(50);
            std::cout << ">> ARENA BONUS! " << monster->getName()
                      << " is consumed by the OCEAN and gains 50 extra health.\n";
        } else {
            monster->decreaseHealth(50);
            std::cout << ">> ARENA DEBUFF! " << monster->getName()
                      << " is drowned by the OCEAN and loses 50 health.\n";
        }
    } else if (arenaType == "forest") {
        if (dynamic_cast<GrassMonster*>(monster) != nullptr) {
            monster->increaseHealth(50);
            std::cout << ">> ARENA BONUS! " << monster->getName()
                      << " entered the Forest arena and gained 50 extra health.\n";
        } else {
            monster->decreaseHealth(50);
            std::cout << ">> ARENA DEBUFF! " << monster->getName()
                      << " is surrounded by trees in the Forest arena and loses 50 health.\n";
        }
    } else if (arenaType == "mountains") {
        if (dynamic_cast<RockMonster*>(monster) != nullptr) {
            monster->increaseHealth(50);
            std::cout << ">> ARENA BONUS! " << monster->getName()
                      << " inhales fresh mountain air and gains 50 extra health.\n";
        } else {
            monster->decreaseHealth(50);
            std::cout << ">> ARENA DEBUFF! " << monster->getName()
                      << " slips while hiking in the Mountains arena and loses 50 health.\n";
        }
    } else if (arenaType == "void") {
        if (dynamic_cast<PoisonMonster*>(monster) != nullptr) {
            monster->increaseHealth(50);
            std::cout << ">> ARENA BONUS! " << monster->getName()
                      << " tumbles into the unfathomable depths of the ABYSS and gains 50 extra health.\n";
        } else {
            monster->decreaseHealth(50);
            std::cout << ">> ARENA DEBUFF! " << monster->getName()
                      << " falls into the void in the Abyss arena and loses 50 health.\n";
        }
    }
}
