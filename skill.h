#ifndef SKILL_H
#define SKILL_H

#include <string>

class Skill {
public:
    Skill(const std::string& name, int attackBoost, int defenseBoost, int healthBoost, int resourceCost);

    std::string getName() const;
    int getAttackBoost() const;
    int getDefenseBoost() const;
    int getHealthBoost() const;
    int getResourceCost() const;

private:
    std::string name;
    int attackBoost;
    int defenseBoost;
    int healthBoost;
    int resourceCost;
};

#endif  // SKILL_H
