#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <random>
#include "item.h"

class Monster {
public:
    Monster(std::string name, int level, int healthPoints, int attackPower, int defensePower);

    virtual ~Monster();

    // Getters
    std::string getName() const;

    int getLevel() const;

    int getHealthPoints() const;

    int getAttackPower() const;

    int getDefensePower() const;

    Item* getEquippedItem() const;


    // Actions
    virtual void attack(Monster *target);

    virtual void takeDamage(int amount);

    virtual void reduceDefense(int amount);

    void equipItem(Item *item);  // function to equip an item

    void increaseHealth(int amount) {
        healthPoints += amount;
    }

protected:
    std::string name;
    int level{};
    int healthPoints;
    int attackPower;
    int defensePower;
    Item *equippedItem;  //  hold the equipped item

};

class FireMonster : public Monster {
public:
    FireMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower);

    ~FireMonster() override;

    void attack(Monster *target) override;
};

class WaterMonster : public Monster {
public:
    WaterMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower);

    ~WaterMonster() override;

    void attack(Monster *target) override;
};

class GrassMonster : public Monster {
public:
    GrassMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower);

    ~GrassMonster() override;

    void attack(Monster *target) override;
};

class RockMonster : public Monster {
public:
    RockMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower);

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
    PoisonMonster(const std::string &name, int level, int healthPoints, int attackPower, int defensePower);

    ~PoisonMonster() override;

    void attack(Monster *target) override;
};

#endif  // MONSTER_H
