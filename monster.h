#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster {
public:
    Monster(const std::string& name, int level, int healthPoints, int attackPower, int defensePower);
    virtual ~Monster();

    // Getters
    std::string getName() const;
    int getLevel() const;
    int getHealthPoints() const;
    int getAttackPower() const;
    int getDefensePower() const;

    // Actions
    virtual void attack(Monster* target);
    virtual void takeDamage(int amount);

protected:
    std::string name;
    int level{};
    int healthPoints;
    int attackPower;
    int defensePower;
};

class FireMonster : public Monster {
public:
    FireMonster(const std::string& name, int level, int healthPoints, int attackPower, int defensePower);
    virtual ~FireMonster();

    void attack(Monster* target) override;
};

class WaterMonster : public Monster {
public:
    WaterMonster(const std::string& name, int level, int healthPoints, int attackPower, int defensePower);
    virtual ~WaterMonster();

    void attack(Monster* target) override;
};

class GrassMonster : public Monster {
public:
    GrassMonster(const std::string& name, int level, int healthPoints, int attackPower, int defensePower);
    virtual ~GrassMonster();

    void attack(Monster* target) override;
};

#endif  // MONSTER_H
