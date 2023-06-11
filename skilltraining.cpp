#include "skilltraining.h"

SkillTraining::SkillTraining() : gen(rd()), dis(0, 99) {
     // Initialize random number generator
    // Here, it assumes you have a function to get available skills list
    skills = getAvailableSkills();
}

void SkillTraining::trainMonster(Monster& monster, const Skill& skill) {
    // Implement the training logic for the monster
    // Enhance the monster's attributes and consume resources, etc.
    int attackBoost = skill.getAttackBoost();
    int defenseBoost = skill.getDefenseBoost();
    int healthBoost = skill.getHealthBoost();
    int resourceCost = skill.getResourceCost();

    if (resourceCost <= monster.getResources()) {
        // Check if the resources are sufficient
        monster.decreaseResources(resourceCost);
        increaseMonsterAttributes(monster, attackBoost, defenseBoost, healthBoost);
    } else {
        // Logic for insufficient resources
        // You can throw an exception or output an error message, etc.
    }
}

void SkillTraining::increaseMonsterAttributes(Monster& monster, int attackBoost, int defenseBoost, int healthBoost) {
    // Increase the monster's attributes
    monster.increaseAttack(attackBoost);
    monster.increaseDefense(defenseBoost);
    monster.increaseHealth(healthBoost);
}
