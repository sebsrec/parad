#include <string>
#include <random>
#include <iostream>
#include <vector>
#include "monster.h"

Monster *selectMonster(const Trainer &player) {
    int choice;

    std::cout << "Select your Monster (1-5): " << std::endl;
    std::cout << "1. Drogon 150 HP  30 DMG  5 DEF\n\t-extra damage chance\n\t-Spell: fireball\n" << std::endl;
    std::cout << "2. Rocko 260 HP  25 DMG  0 DEF\n\t-Damage block chance\n\t-Spell: bigrock\n" << std::endl;
    std::cout << "3. Aqua 200 HP  20 DMG  25 DEF\n\t-Lifesteal chance\n\t-Spell: waterfall\n" << std::endl;
    std::cout << "4. Leafy 200 HP  25 DMG  15 DEF\n\t-Armor reduction chance\n\t-Spell: keepstill\n" << std::endl;
    std::cout << "5. Venomancer 100 HP  20 DMG  15 DEF\n\t-Instant kill chance\n\t-Spell: manavoid\n" << std::endl;
    std::cin >> choice;

    Monster *selectedMonster = nullptr; // no monster was selected or invalid choice

    switch (choice) {
        case 1:
            std::cout << ">> You selected Drogon\n";
            selectedMonster = player.getMonster(0);
            break;
        case 2:
            std::cout << ">> You selected Rocko.\n";
            selectedMonster = player.getMonster(1);
            break;
        case 3:
            std::cout << ">> You selected Aqua\n";
            selectedMonster = player.getMonster(2);
            break;
        case 4:
            std::cout << ">> You selected Leafy\n";
            selectedMonster = player.getMonster(3);
            break;
        case 5:
            std::cout << ">> You selected Venomancer\n";
            selectedMonster = player.getMonster(4);
            break;
    }
    std::cout << "\n";
    return selectedMonster;
}

Monster* randomMonster(const Monster* player2Monster) {
    std::vector<std::string> monsterNames = {"Drogon", "Leafy", "Aqua", "Rocko", "Venomancer"};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, monsterNames.size() - 1);

    std::string name = ""; // Initialize with an empty string

    name = monsterNames[dis(gen)]; // Assign a random monster name

    // Create the corresponding monster object based on the name
    if (name == "Drogon") {
        return new FireMonster(name, 5, 150, 30, 5, 100);
    } else if (name == "Leafy") {
        return new GrassMonster(name, 5, 200, 25, 15, 100);
    } else if (name == "Aqua") {
        return new WaterMonster(name, 5, 200, 20, 25, 100);
    } else if (name == "Rocko") {
        return new RockMonster(name, 5, 260, 25, 0, 100);
    } else if (name == "Venomancer") {
        return new PoisonMonster(name, 5, 100, 20, 15, 100);
    }

    return nullptr; // Return nullptr if the name doesn't match any monster
}

