#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <vector>

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

class SkillSet {
public:
    SkillSet();
    ~SkillSet();

    void addSkill(const Skill& skill);
    void removeSkill(const std::string& name);
    bool hasSkill(const std::string& name) const;
    Skill* getSkill(const std::string& name);
    const std::vector<Skill>& getAllSkills() const;

private:
    std::vector<Skill> skills;
};

#endif  // SKILL_H
