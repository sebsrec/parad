/*
CHINPOKOMON
The battle arena is chosen randomly.
The CPU selects a monster at random.
An item is randomly assigned to both player and CPU.
Use the correct spell in each monster!
*/

#include "monster.h"
#include "trainer.h"
#include "arena.h"
#include "selectArena.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "selectMonster.h"
#include <random>
Skill* generateRandomSkill(); // forward declaration of the generateRandomSkill() function

int main() {

    std::cout << "Press  ENTER to continue..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    //create trainer instances
    Trainer player1("Player 1");
    Trainer player2("Computer");

    //create monster instances
    auto *fireMonster = new FireMonster("Drogon", 5, 150, 30, 5, 100);
    auto *grassMonster = new GrassMonster("Leafy", 5, 200, 25, 15, 100);
    auto *waterMonster = new WaterMonster("Aqua", 5, 200, 20, 25, 100);
    auto *rockMonster = new RockMonster("Rocko", 5, 260, 25, 0, 100);
    auto *poisonMonster = new PoisonMonster("Venomancer", 5, 100, 20, 15, 100);

    //create item instances
    std::vector<Item *> items;
    items.push_back(new Item("Health Potion (+50 extra health)", 0, 0, 50,0));
    items.push_back(new Item("Shield Potion (+50 extra defense)", 0, 50, 0,0));
    items.push_back(new Item("Damage Potion (+20 extra damage)", 20, 0, 0,0));
    items.push_back(new Item("Mana Potion (+20 extra damage)", 0, 0, 0,20));



    //add monsters to stl container
    player1.addMonster(fireMonster, rockMonster, waterMonster, grassMonster, poisonMonster);
    player2.addMonster(fireMonster, rockMonster, waterMonster, grassMonster, poisonMonster);

    //select monsters to fight
    //Player 1 Selects monster
    Monster *player1Monster = selectMonster(player1);
    //Computer Randoms monster
    Monster *player2Monster = randomMonster(player2Monster);
    //Monster *player2Monster = fireMonster;

    player1Monster->setTarget(player2Monster);


    // Randomly assign items to monsters
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, items.size() - 1);
    Item* randomItemP1 = items[dis(gen)];
    Item* randomItemP2 = items[dis(gen)];
    player1Monster->equipItem(randomItemP1);
    player2Monster->equipItem(randomItemP2);

    std::cout << "Player 1 found: " << player1Monster->getEquippedItem()->getName() << std::endl;
    std::cout << "Computer chose: " << player2Monster->getEquippedItem()->getName() << std::endl;

    // Create an instance of Arena
    Arena arena(getRandomArenaType());
    std::cout << "\nBattle Arena: " << arena.getArenaType() << std::endl << "\n";
    arena.enterArena(player1Monster);
    arena.enterArena(player2Monster);

    // Create skill instances
    Skill fireballSkill("fireball");
    Skill waterfallSkill("waterfall");
    Skill bigRockSkill("bigrock");
    Skill keepStillSkill("keepstill");

    //Display stats with boosts:
    std::cout << "\nPlayer 1: " << player1Monster->getName() << " lvl(" << player1Monster->getLevel() << "):  "
              << player1Monster->getHealthPoints() << " HP  " << player1Monster->getAttackPower() << " DMG  "
              << player1Monster->getDefensePower() << " DEF  " << player1Monster->getMana() << " MANA  " << std::endl;
    std::cout << "Computer: " << player2Monster->getName() << " lvl(" << player2Monster->getLevel() << "):  "
              << player2Monster->getHealthPoints() << " HP  " << player2Monster->getAttackPower() << " DMG  "
              << player2Monster->getDefensePower() << " DEF  " << player1Monster->getMana() << " MANA  " << "\n";

    //Wait user input to start!
    std::cout << "\nPress ENTER to start battle!" << std::endl;
    std::cin.clear(); // Clear any error flags on cin
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::cin.get(); // Wait for user to press Enter

    // Game starts!
    std::cout << "\nBATTLE BEGINS!" << std::endl;

    //fight until health reaches 0
    while (player1Monster->getHealthPoints() > 0 && player2Monster->getHealthPoints() > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\n>> " << player1Monster->getName() << "'s HP: " << player1Monster->getHealthPoints()
                  << "  Mana: " << player1Monster->getMana() << std::endl;
        std::cout << ">> " << player2Monster->getName() << "'s HP: " << player2Monster->getHealthPoints()
                  << "  Mana: " << player2Monster->getMana() << std::endl << "\n";

        // Player 1 selects a skill
        std::cout << "Player 1, select a skill: ";
        std::string skillType;
        std::cin >> skillType;
        Skill skill(skillType);
        skill.chooseSkill(player1Monster);

        // Player 1 attacks player 2
        std::this_thread::sleep_for(std::chrono::seconds(1));
        player1Monster->attack(player2Monster);

        // Check if player 2 is defeated
        if (player2Monster->getHealthPoints() <= 0 && player1Monster->getHealthPoints() > 0) {
            std::cout << "\nPlayer 1 wins!" << std::endl;
            break;
        }

        // Player 2 selects a skill
        Skill* randomSkill = generateRandomSkill();
        randomSkill->chooseSkill(player2Monster);

        // Player 2 attacks player 1
        std::this_thread::sleep_for(std::chrono::seconds(1));
        player2Monster->attack(player1Monster);

        // Check if player 1 is defeated
        if (player1Monster->getHealthPoints() <= 0 && player2Monster->getHealthPoints() > 0) {
            std::cout << "\nComputer wins!" << std::endl;
            break;
        }

        // Check if both players are defeated
        if (player1Monster->getHealthPoints() == 0 && player2Monster->getHealthPoints() == 0) {
            std::cout << "\nHurray, both lose!" << std::endl;
            break;
        }
    }

    player1.removeMonster();
    player2.removeMonster();
    delete fireMonster;
    delete waterMonster;
    delete grassMonster;
    delete rockMonster;
    delete poisonMonster;

    //Note: Monster instances will delete the Item objects in their destructors.
    //delete randomSkill;
    return 0;
}