#include "monster.h"
#include "trainer.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "selectMonster.h"



int main() {
    //create trainer instances
    Trainer player1("Player 1");
    Trainer player2("Player 2");

    //create monster instances
    auto* fireMonster = new FireMonster("Drogon", 5, 200, 30, 10);
    auto* waterMonster = new WaterMonster("Aqua", 5, 200, 20, 20);
    auto* grassMonster = new GrassMonster("Leafy", 5, 200, 25, 15);
    auto* rockMonster = new RockMonster("Rocko", 5, 200, 25, 15);
    auto* poisonMonster = new PoisonMonster("Venomancer", 5, 200, 25, 15);


    //add monsters to stl container
    player1.addMonster(fireMonster, rockMonster, waterMonster, grassMonster, poisonMonster);
    player2.addMonster(fireMonster, rockMonster, waterMonster, grassMonster, poisonMonster);

    //select monsters to fight
    Monster* player1Monster = selectMonster(player1);
    Monster* player2Monster = selectMonster(player2);

    //fight until health reaches 0
    while (player1Monster->getHealthPoints() > 0 && player2Monster->getHealthPoints() > 0) {

        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\n" << player1Monster->getName() << "'s HP: " << player1Monster->getHealthPoints() << std::endl;
        std::cout << player2Monster->getName() << "'s HP: " << player2Monster->getHealthPoints() << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
        player1Monster->attack(player2Monster);

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

    return 0;
}