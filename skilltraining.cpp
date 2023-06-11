#include "skilltraining.h"
#include <iostream>

Player::Player() : attack(10), defense(10), health(100), resources(100) {}

void Player::trainMonster(Monster& monster, const Skill& skill) {
    // check the resource is enough
    if (resources < skill.getResourceCost()) {
        std::cout << "no resource，u can not training " << std::endl;
        return;
    }

    // 消耗资源
    resources -= skill.getResourceCost();

    // 提升怪物属性
    increaseMonsterAttributes(monster, skill.getAttackBoost(), skill.getDefenseBoost(), skill.getHealthBoost());

    std::cout << "training finish ，the monster is stronger" << std::endl;
}

void Player::increaseMonsterAttributes(Monster& monster, int attackBoost, int defenseBoost, int healthBoost) {
    monster.increaseAttack(attackBoost);
    monster.increaseDefense(defenseBoost);
    monster.increaseHealth(healthBoost);
}
//
// Created by 李任骁 on 2023/6/11.
//
