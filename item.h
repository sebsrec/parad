#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(const std::string& name, int bonusDamage, int bonusDefense,  int bonusHealth);
    ~Item();

    // Getters
    std::string getName() const;
    int getBonusDamage() const;
    int getBonusDefense() const;
    int getBonusHealth() const;

    // Setter
    void setItem(Item* newItem);

private:
    std::string name;
    int bonusDamage;
    int bonusDefense;
    int bonusHealth;

    Item* item;
};

#endif  // ITEM_H