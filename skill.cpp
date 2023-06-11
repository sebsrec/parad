#include <string>

class Skill {
public:
    Skill(const std::string& name, int attackBoost, int defenseBoost, int healthBoost, int resourceCost)
            : name(name), attackBoost(attackBoost), defenseBoost(defenseBoost),
              healthBoost(healthBoost), resourceCost(resourceCost) {}

    // Getter函数
    std::string getName() const { return name; }
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
