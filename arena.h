#ifndef ARENA_H
#define ARENA_H

#include <string>
#include "monster.h"

class Arena {
private:
    std::string arenaType;

public:
    Arena(const std::string& type);
    std::string getArenaType() const;
    void enterArena(Monster* monster);
};

#endif  // ARENA_H
