#include "monster.h"
#include "trainer.h"
#include "arena.h"
#include "selectArena.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "selectMonster.h"
#include <random>




int main() {
    //create trainer instances
    Trainer player1("Player 1");
    Trainer player2("Player 2");

    //create monster instances
    auto *fireMonster = new FireMonster("Drogon", 5, 150, 30, 5);
    auto *grassMonster = new GrassMonster("Leafy", 5, 200, 25, 15);
    auto *waterMonster = new WaterMonster("Aqua", 5, 250, 20, 20);
    auto *rockMonster = new RockMonster("Rocko", 5, 260, 25, 15);
    auto *poisonMonster = new PoisonMonster("Venomancer", 5, 100, 20, 15);

    //create item instances
    std::vector<Item*> items;
    items.push_back(new Item("Health Potion (+50 extra health)", 0, 0, 50));
    items.push_back(new Item("Shield Potion (+50 extra defense)", 0, 50, 0));
    items.push_back(new Item("Damage Potion (+20 extra damage)", 20, 0, 0));

    //add monsters to stl container
    player1.addMonster(fireMonster, rockMonster, waterMonster, grassMonster, poisonMonster);
    player2.addMonster(fireMonster, rockMonster, waterMonster, grassMonster, poisonMonster);

    //select monsters to fight
    Monster *player1Monster = selectMonster(player1);
    Monster *player2Monster = selectMonster(player2);

    // Randomly give an item to a monster
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, items.size() - 1);

    Item* randomItemP1 = items[dis(gen)];
    Item* randomItemP2 = items[dis(gen)];
    player1Monster->equipItem(randomItemP1);
    player2Monster->equipItem(randomItemP2);

    std::cout << "Player 1 has: " << player1Monster->getEquippedItem()->getName() << std::endl;
    std::cout << "Player 2 has: " << player2Monster->getEquippedItem()->getName() << std::endl;

    // Create an instance of Arena, always random
    Arena arena(getRandomArenaType());
    std::cout << "\nBattle Arena: " << arena.getArenaType() << std::endl;
    arena.enterArena(player1Monster);
    arena.enterArena(player2Monster);

    // Game starts!
    std::cout << "\nBATTLE BEGINS!" << std::endl;

    //fight until health reaches 0
    while (player1Monster->getHealthPoints() > 0 && player2Monster->getHealthPoints() > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\n>> " << player1Monster->getName() << "'s HP: " << player1Monster->getHealthPoints() << std::endl;
        std::cout << ">> " << player2Monster->getName() << "'s HP: " << player2Monster->getHealthPoints() << "\n" << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
        player1Monster->attack(player2Monster);

        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\n>> " << player1Monster->getName() << "'s HP: " << player1Monster->getHealthPoints() << std::endl;
        std::cout << ">> " << player2Monster->getName() << "'s HP: " << player2Monster->getHealthPoints() << "\n" << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
        player2Monster->attack(player1Monster);

        if (player1Monster->getHealthPoints() <= 0 && player2Monster->getHealthPoints() != 0) {
            std::cout << "\nPlayer 2 wins!" << std::endl;
        }
        if (player2Monster->getHealthPoints() <= 0 && player1Monster->getHealthPoints() != 0) {
            std::cout << "\nPlayer 1 wins!" << std::endl;
        }
        if (player1Monster->getHealthPoints() == 0 && player2Monster->getHealthPoints() == 0) {
            std::cout << "\nHurray both lose!" << std::endl;
        }
    }

    player1.removeMonster();
    player2.removeMonster();

    delete fireMonster;
    delete waterMonster;
    delete grassMonster;
    delete rockMonster;
    delete poisonMonster;
   //>> Note: Monster instances will delete the Item objects in their destructors.
    return 0;
}