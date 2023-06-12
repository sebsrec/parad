#include "trainer.h"

Trainer::Trainer(const std::string& name) : name(name) {}

Trainer::~Trainer() {
    for (Monster* monster : monsters) {
        delete monster;
    }
    monsters.clear();
}

std::string Trainer::getName() const {
    return name;
}

int Trainer::getNumMonsters() const {
    return monsters.size();
}

Monster* Trainer::getMonster(int index) const {
    if (index >= 0 && index < monsters.size()) {
        return monsters[index];
    }
    return nullptr;
}

void Trainer::addMonster(Monster* monster) {
    monsters.push_back(monster);
}
