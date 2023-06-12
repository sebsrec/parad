#define SELECTMONSTER_H

#include <string>

Monster *selectMonster(const Trainer &player) {
    int choice;

    std::cout << "Select your Monster (1-5): " << std::endl;
    std::cout << "1. Drogon 150 HP  30 DMG  5 DEF\n\t-extra damage chance\n"<<std::endl;
    std::cout << "2. Rocko 260 HP  25 DMG  15 DEF\n\t-Damage Block chance\n"<<std::endl;
    std::cout << "3. Aqua 250 HP  20 DMG  20 DEF\n\t-Lifesteal chance\n"<<std::endl;
    std::cout << "4. Leafy 200 HP  25 DMG  15 DEF\n\t-Armor reduction chance\n"<<std::endl;
    std::cout << "5. Venomancer 100 HP  20 DMG  15 DEF\n\t-Instant kill chance\n"<<std::endl;
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
Monster* randomMonster() {
    std::vector<std::string> monsterNames = {"Drogon", "Leafy", "Aqua", "Rocko", "Venomancer"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, monsterNames.size() - 1);

    std::string name = monsterNames[dis(gen)];
    int level = 5;  // level is fixed for now
    int healthPoints, attackPoints, defensePoints;

    if (name == "Drogon") {
        healthPoints = 150;
        attackPoints = 30;
        defensePoints = 5;

    } else if (name == "Leafy") {
        healthPoints = 200;
        attackPoints = 25;
        defensePoints = 15;

    } else if (name == "Aqua") {
        healthPoints = 250;
        attackPoints = 20;
        defensePoints = 20;

    } else if (name == "Rocko") {
        healthPoints = 260;
        attackPoints = 25;
        defensePoints = 15;

    } else if (name == "Venomancer") {
        healthPoints = 100;
        attackPoints = 20;
        defensePoints = 15;

    }

    Monster* monster = new Monster(name, level, healthPoints, attackPoints, defensePoints);
    std::cout << ">> Computer selected " << monster->getName() << std::endl << std::endl;
    return monster;
}
