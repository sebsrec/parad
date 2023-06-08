#ifndef TRAINER_H
#define TRAINER_H

#include "monster.h"
#include <string>
#include <vector>

class Trainer {
public:
    explicit Trainer(const std::string& name);
    ~Trainer();

    // Getters
    std::string getName() const;
    int getNumMonsters() const;
    Monster* getMonster(int index) const;

    // Actions
    void addMonster(Monster* monster, ...) {
        monsters.push_back(monster);

        va_list args;
        va_start(args, monster);

        Monster* nextMonster = nullptr;
        while ((nextMonster = va_arg(args, Monster*)) != nullptr) {
            monsters.push_back(nextMonster);
        }

        va_end(args);
    }

    void removeMonster() {
        for (auto monster : monsters) {
            delete monster;
        }
        monsters.clear();
    }
private:
    std::string name;
    std::vector<Monster*> monsters; // STL container to store monsters
    void addMonster(Monster *monster);
};

#endif  // TRAINER_H