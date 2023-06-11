#ifndef SKILLTRAINING_H
#define SKILLTRAINING_H

#include <string>
#include <vector>
#include <random>
#include "skill.h"
#include "monster.h"

class SkillTraining {
public:
    SkillTraining();

    void trainMonster(Monster& monster, const Skill& skill);
    void increaseMonsterAttributes(Monster& monster, int attackBoost, int defenseBoost, int healthBoost);

private:
    std::vector<Skill> skills;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<int> dis;
};

#endif  // SKILLTRAINING_H
