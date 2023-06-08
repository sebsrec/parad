#define SELECTMONSTER_H

#include <string>

Monster* selectMonster(const Trainer& player) {
    int choice;

    std::cout << "Monsters:\n";
    std::cout << "1. Drogon (extra damage chance)\n";
    std::cout << "2. Vaporeon (Lifesteal chance)\n";
    std::cout << "3. Leafy (Armor reduction chance)\n";
    std::cout << "4. Rocko (Damage Block chance)\n";

    std::cout << "Select your Monster (1-4): ";

    std::cin >> choice;

    Monster* selectedMonster = nullptr;

    switch (choice) {
        case 1:
            std::cout << "You selected Drogon\n";
            selectedMonster = player.getMonster(0);
            break;
        case 2:
            std::cout << "You selected Vaporeon.\n";
            selectedMonster = player.getMonster(1);
            break;
        case 3:
            std::cout << "You selected Leafy\n";
            selectedMonster = player.getMonster(2);
            break;
        case 4:
            std::cout << "You selected Rocko\n";
            selectedMonster = player.getMonster(3);
            break;
    }

    return selectedMonster;
}
