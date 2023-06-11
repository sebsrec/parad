#include "skill.h"

Skill::Skill(const std::string& name, int attackBoost, int defenseBoost, int healthBoost, int resourceCost)
    : name(name), attackBoost(attackBoost), defenseBoost(defenseBoost), healthBoost(healthBoost), resourceCost(resourceCost) {}

std::string Skill::getName() const {
    return name;
}

int Skill::getAttackBoost() const {
    return attackBoost;
}

int Skill::getDefenseBoost() const {
    return defenseBoost;
}

int Skill::getHealthBoost() const {
    return healthBoost;
}

int Skill::getResourceCost() const {
    return resourceCost;
}

SkillSet::SkillSet() {}

SkillSet::~SkillSet() {}

void SkillSet::addSkill(const Skill& skill) {
    skills.push_back(skill);
}

void SkillSet::removeSkill(const std::string& name) {
    skills.erase(std::remove_if(skills.begin(), skills.end(), [&name](const Skill& skill) {
        return skill.getName() == name;
    }), skills.end());
}

bool SkillSet::hasSkill(const std::string& name) const {
    return std::find_if(skills.begin(), skills.end(), [&name](const Skill& skill) {
        return skill.getName() == name;
    }) != skills.end();
}

Skill* SkillSet::getSkill(const std::string& name) {
    auto it = std::find_if(skills.begin(), skills.end(), [&name](const Skill& skill) {
        return skill.getName() == name;
    });

    if (it != skills.end()) {
        return &(*it);
    }

    return nullptr;
}

const std::vector<Skill>& SkillSet::getAllSkills() const {
    return skills;
}
