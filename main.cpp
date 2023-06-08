#include "monster.h"
#include "trainer.h"
#include <iostream>
#include <chrono>
#include <thread>


int main() {
    Trainer player1("Player 1");
    Trainer player2("Player 2");

    auto* fireMonster = new FireMonster("Flareon", 5, 200, 30, 10);
    auto* waterMonster = new WaterMonster("Vaporeon", 5, 200, 20, 20);
    auto* grassMonster = new GrassMonster("Leafeon", 5, 200, 25, 15);

    player1.addMonster(fireMonster);
    player2.addMonster(waterMonster);
    player2.addMonster(grassMonster);

    std::cout << player1.getName() << " has " << player1.getNumMonsters() << " monster(s).\n";
    std::cout << player2.getName() << " has " << player2.getNumMonsters() << " monster(s).\n";

    Monster *player1Monster = player1.getMonster(0);
    Monster *player2Monster = player2.getMonster(1);

    while (player1Monster->getHealthPoints() > 0 && player2Monster->getHealthPoints() > 0) {
        player1Monster->attack(player2Monster);
        player2Monster->attack(player1Monster);

        std::cout << player1Monster->getName() << "'s HP: " << player1Monster->getHealthPoints() << std::endl;
        std::cout << player2Monster->getName() << "'s HP: " << player2Monster->getHealthPoints() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (player1Monster->getHealthPoints() <= 0) {
            std::cout << "Player 2 wins!" << std::endl;
        }
        if (player2Monster->getHealthPoints() <= 0) {
            std::cout << "Player 1 wins!" << std::endl;
        }
    }

    player1.removeMonster(0);
    player2.removeMonster(0);

    delete fireMonster;
    delete waterMonster;
    delete grassMonster;

    return 0;
}

