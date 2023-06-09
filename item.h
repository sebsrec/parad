#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(const std::string& name, int bonusDamage);
    ~Item();

    // Getters
    std::string getName() const;
    int getBonusDamage() const;

    // Setter
    void setItem(Item* newItem);

private:
    std::string name;
    int bonusDamage;
    Item* item;
};

#endif  // ITEM_H