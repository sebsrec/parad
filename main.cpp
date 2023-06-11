#include "monster.h"
#include "trainer.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "selectMonster.h"
#include "skill.h"
#include "skilltraining.h"

int main() {
    Monster* player1Monster = nullptr;
    Monster* player2Monster = nullptr;

    // Create some skill objects
    Skill skill1("Fireball", 10, 0, 0, 5);
    Skill skill2("Healing Touch", 0, 0, 20, 8);
    Skill skill3("Shield Bash", 5, 15, 0, 10);

    // Create a skill set object
    SkillSet skillSet;

    // Add skills to the set
    skillSet.addSkill(skill1);
    skillSet.addSkill(skill2);
    skillSet.addSkill(skill3);

    // Check if the skill set contains a specific skill
    std::cout << "Skill Set contains Fireball: " << (skillSet.hasSkill("Fireball") ? "Yes" : "No") << std::endl;
    std::cout << "Skill Set contains Ice Blast: " << (skillSet.hasSkill("Ice Blast") ? "Yes" : "No") << std::endl;

    // Get all skills from the set and print their properties
    const std::vector<Skill>& allSkills = skillSet.getAllSkills();
    std::cout << "All Skills:" << std::endl;
    for (const Skill& skill : allSkills) {
        std::cout << "Name: " << skill.getName() << std::endl;
        std::cout << "Attack Boost: " << skill.getAttackBoost() << std::endl;
        std::cout << "Defense Boost: " << skill.getDefenseBoost() << std::endl;
        std::cout << "Health Boost: " << skill.getHealthBoost() << std::endl;
        std::cout << "Resource Cost: " << skill.getResourceCost() << std::endl;
        std::cout << std::endl;
    }

    // Remove a skill from the set
    skillSet.removeSkill("Healing Touch");

    // Get all skills from the updated set and print them
    std::cout << "Updated Skill Set:" << std::endl;
    const std::vector<Skill>& updatedSkills = skillSet.getAllSkills();
    for (const Skill& skill : updatedSkills) {
        std::cout << "Name: " << skill.getName() << std::endl;
        std::cout << "Attack Boost: " << skill.getAttackBoost() << std::endl;
        std::cout << "Defense Boost: " << skill.getDefenseBoost() << std::endl;
        std::cout << "Health Boost: " << skill.getHealthBoost() << std::endl;
        std::cout << "Resource Cost: " << skill.getResourceCost() << std::endl;
        std::cout << std::endl;
    }

    // Create trainer instances
    Trainer player1("Player 1");
    Trainer player2("Player 2");

    // Create monster instances
    auto* fireMonster = new FireMonster("Drogon", 5, 200, 30, 10);
    auto* waterMonster = new WaterMonster("Aqua", 5, 200, 20, 20);
    auto* grassMonster = new GrassMonster("Leafy", 5, 200, 25, 15);
    auto* rockMonster = new RockMonster("Rocko", 5, 200, 25, 15);
    auto* poisonMonster = new PoisonMonster("Venomancer", 5, 200, 25, 15);

    // Print initial health points of the monsters
    std::cout << "\n" << player1Monster->getName() << "'s HP: " << player1Monster->getHealthPoints() << std::endl;
    std::cout << player2Monster->getName() << "'s HP: " << player2Monster->getHealthPoints() << "\n" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));
    player1Monster->attack(player2Monster);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\n" << player1Monster->getName() << "'s HP: " << player1Monster->getHealthPoints() << std::endl;
    std::cout << player2Monster->getName() << "'s HP: " << player2Monster->getHealthPoints() << "\n" << std::endl;

    // Add monsters to the trainers' containers
    player1.addMonsters(fireMonster, rockMonster, waterMonster, grassMonster, poisonMonster, nullptr);
    player2.addMonsters(fireMonster, rockMonster, waterMonster, grassMonster, poisonMonster, nullptr);

    Item* itemP1 = nullptr;
    Item* itemP2 = nullptr;

    // Select monsters for battle
    player1Monster = selectMonster(player1);
    player2Monster = selectMonster(player2);

    // Equip items to the monsters
    player1Monster->equipItem(itemP1);
    player2Monster->equipItem(itemP2);

    std::cout << "Player 1 has: " << itemP1->getName() << std::endl;
    std::cout << "Player 2 has: " << itemP2->getName() << std::endl;

    // Continuously battle until one monster's health points reach zero
    while (player1Monster->getHealthPoints() > 0 && player2Monster->getHealthPoints() > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\n" << player1Monster->getName() << "'s HP: " << player1Monster->getHealthPoints() << std::endl;
        std::cout << player2Monster->getName() << "'s HP: " << player2Monster->getHealthPoints() << "\n" << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
        player1Monster->attack(player2Monster);

        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\n" << player1Monster->getName() << "'s HP: " << player1Monster->getHealthPoints() << std::endl;
        std::cout << player2Monster->getName() << "'s HP: " << player2Monster->getHealthPoints() << "\n" << std::endl;
    }

    player1.removeMonster();
    player2.removeMonster();

    delete fireMonster;
    delete waterMonster;
    delete grassMonster;
    delete rockMonster;
    delete poisonMonster;
    delete itemP1;
    delete itemP2;

    return 0;
}
