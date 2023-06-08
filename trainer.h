#ifndef TRAINER_H
#define TRAINER_H

#include "monster.h"
#include <string>
#include <vector>

class Trainer {
public:
    Trainer(const std::string& name);
    ~Trainer();

    // Getters
    std::string getName() const;
    int getNumMonsters() const;
    Monster* getMonster(int index) const;

    // Actions
    void addMonster(Monster* monster);
    void removeMonster(int index);

private:
    std::string name;
    std::vector<Monster*> monsters;
};

#endif  // TRAINER_H
