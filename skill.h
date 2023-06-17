#ifndef SKILL_H
#define SKILL_H

#include <string>

class Monster; // Forward declaration of the Monster class

class Skill {
private:
    std::string skillType;

public:
    explicit Skill(const std::string& type);

    std::string getSkillType() const;

    void chooseSkill(Monster* monster);

    std::string getName() const;
};

#endif // SKILL_H

