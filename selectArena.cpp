#include "selectArena.h"
#include <random>

std::string getRandomArenaType() {
    std::string arenaTypes[] = { "ocean", "hell", "void", "forest", "mountains"  };
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(0, 4);
    int randomIndex = dist(rng);
    return arenaTypes[randomIndex];

}
