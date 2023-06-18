#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <random>
#include "item.h"
#include "skill.h"

class Monster {

    Monster* target; // Add a member variable to store the target monster

public:
    Monster(std::string name, int level, int healthPoints, int attackPower, int defensePower, int mana);

    virtual ~Monster();

    // Getters
    std::string getName() const;

    int getLevel() const;

    int getHealthPoints() const;

    int getAttackPower() const;

    int getDefensePower() const;

    int getMana() const;

    Item* getEquippedItem() const;


    // Actions
    virtual void attack(Monster *target);

    virtual void takeDamage(int amount);

    virtual void reduceDefense(int amount);

    void equipItem(Item *item);  // function to equip an item

    void increaseHealth(int amount) {
        healthPoints += amount;
    }

    void setTarget(Monster* target);
    Monster* getTarget() const;

    // Skill related functions
    bool hasSkill() const;

    Skill* getSkill() const;

    void setSkill(Skill* skill);

    void increaseDamage(int amount);

    void decreaseDamage(int amount);

    void decreaseHealth(int amount);

    void increaseDefense(int amount);

    void decreaseMana(int amount);

private:

protected:
    std::string name;
    int level{};
    int healthPoints;
    int attackPower;
    int defensePower;
    Item *equippedItem;  //  hold the equipped item
    Skill* skill; // Pointer to the skill of the monster -> hold skill, analog to hold item.
    int mana;

};

// Inline function definitions for getTarget() and setTarget()
inline Monster* Monster::getTarget() const {
    return target;
}

inline void Monster::setTarget(Monster* target) {
    this->target = target;
}


class FireMonster : public Monster {
public:
    FireMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower, int mana);

    ~FireMonster() override;

    void attack(Monster *target) override;
};

class WaterMonster : public Monster {
public:
    WaterMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower, int mana);

    ~WaterMonster() override;

    void attack(Monster *target) override;
};

class GrassMonster : public Monster {
public:
    GrassMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower, int mana);

    ~GrassMonster() override;

    void attack(Monster *target) override;
};

class RockMonster : public Monster {
public:
    RockMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower, int mana);

    ~RockMonster() override;

    void attack(Monster *target) override;

    static Item* getRandomItem(const std::vector<Item*>& items) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, items.size() - 1);
        return items[dis(gen)];
    }
};

class PoisonMonster : public Monster {
public:
    PoisonMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower, int mana);

    ~PoisonMonster() override;

    void attack(Monster *target) override;
};

#endif  // MONSTER_H