#include "monster.h"
#include "trainer.h"
#include <iostream>

int main() {
    Trainer player1("Player 1");
    Trainer player2("Player 2");

    Monster* fireMonster = new FireMonster("Flareon", 10);
    Monster* waterMonster = new WaterMonster("Vaporeon", 12);
    Monster* grassMonster = new GrassMonster("Leafeon", 8);

    player1.addMonster(fireMonster);
    player2.addMonster(waterMonster);
    player2.addMonster(grassMonster);

    std::cout << player1.getName() << " has " << player1.getNumMonsters() << " monster(s).\n";
    std::cout << player2.getName() << " has " << player2.getNumMonsters() << " monster(s).\n";

    Monster* player1Monster = player1.getMonster(0);
    Monster* player2Monster = player2.getMonster(0);

    if (player1Monster && player2Monster) {
        player1Monster->attack(player2Monster);
        player2Monster->attack(player1Monster);
    }

    std::cout << player1Monster->getName() << "'s HP: " << player1Monster->getHealthPoints() << std::endl;
    std::cout << player2Monster->getName() << "'s HP: " << player2Monster->getHealthPoints() << std::endl;

    player1.removeMonster(0);
    player2.removeMonster(0);

    delete fireMonster;
    delete waterMonster;
    delete grassMonster;

    return 0;
}
