#include <iostream>
#include "arena.h"

Arena::Arena(const std::string &type) : arenaType(type) {}

std::string Arena::getArenaType() const {
    return arenaType;
}

void Arena::enterArena(Monster *monster) {
    //  special boost based on the arena type
    if (arenaType == "hell" && dynamic_cast<FireMonster *>(monster) != nullptr) {
        monster->increaseHealth(50);
        std::cout << ">> ARENA BONUS! Monster " << monster->getName() << " descended into the depths of HELL and gained 50 extra health.\n";

    } else if (arenaType == "ocean" && dynamic_cast<WaterMonster *>(monster) != nullptr) {
        monster->increaseHealth(50);
        std::cout << ">> ARENA BONUS! Monster " << monster->getName() << " is consumed by the OCEAN and gained 50 extra health.\n";

    } else if (arenaType == "forest" && dynamic_cast<GrassMonster *>(monster) != nullptr) {
        monster->increaseHealth(50);
        std::cout << ">> ARENA BONUS! Monster " << monster->getName() << " entered the Forest arena and gained 50 extra health.\n";

    } else if (arenaType == "void" && dynamic_cast<PoisonMonster *>(monster) != nullptr) {
        monster->increaseHealth(50);
        std::cout << ">> ARENA BONUS! Monster " << monster->getName() << " tumbles into the unfathomable depths of the ABYSS and gained 50 extra health.\n";

    } else if (arenaType == "mountains" && dynamic_cast<RockMonster *>(monster) != nullptr) {
        monster->increaseHealth(50);
        std::cout << ">> ARENA BONUS! Monster " << monster->getName() << " entered the Mountains arena and gained 50 extra health.\n";
    }

}