#include "skillpool.h"
#include <random>

SkillPool::SkillPool() {
    skillTypes = { "fireball", "waterfall", "bigrock", "keepstill" };
}

std::string SkillPool::getRandomSkillType() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(0, skillTypes.size() - 1);
    int randomIndex = dist(rng);
    return skillTypes[randomIndex];
}
