#ifndef SKILLTRAINING_H
#define SKILLTRAINING_H

#include <string>
#include <vector>
#include <random>

//
class Monster {
public:
    Monster(const std::string& name, int attack, int defense, int health)
            : name(name), attack(attack), defense(defense), health(health) {}

    // 其他成员函数...

private:
    std::string name;
    int attack;
    int defense;
    int health;
};

// 技能
class Skill {
public:
    Skill(const std::string& name, int attackBoost, int defenseBoost, int healthBoost, int resourceCost)
            : name(name), attackBoost(attackBoost), defenseBoost(defenseBoost),
              healthBoost(healthBoost), resourceCost(resourceCost) {}

    int getAttackBoost() const { return attackBoost; }
    int getDefenseBoost() const { return defenseBoost; }
    int getHealthBoost() const { return healthBoost; }
    int getResourceCost() const { return resourceCost; }

private:
    std::string name;
    int attackBoost;
    int defenseBoost;
    int healthBoost;
    int resourceCost;
};

// 玩家
class Player {
public:
    Player();

    void trainMonster(Monster& monster, const Skill& skill);
    void increaseMonsterAttributes(Monster& monster, int attackBoost, int defenseBoost, int healthBoost);

    // 获取玩家属性和资源的函数（getter方法）...

private:
    int attack;
    int defense;
    int health;
    int resources;
};

#endif  // SKILLTRAINING_H
