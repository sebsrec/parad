#ifndef SKILLPOOL_H
#define SKILLPOOL_H

#include <string>
#include <vector>

class SkillPool {
private:
    std::vector<std::string> skillTypes;

public:
    SkillPool();

    std::string getRandomSkillType();
};

#endif // SKILLPOOL_H
