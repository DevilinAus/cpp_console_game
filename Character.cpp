#include "Character.h"

#include <iostream>

Character::Character(const std::string& name, int health, int attackPower)
    : name(name), health(health), attackPower(attackPower) {}

const std::string& Character::getName() const { return name; }
const std::string& Character::getStatusText() const {
    return "The Goblin has " + std::to_string(health) + " health";
}

int Character::attack(Character& enemy) { return enemy.takeDamage(attackPower); };

int Character::takeDamage(int damage) {
    int armour = 0;
    int damageDone = damage - armour;
    std::cout << "damage is: " << damage << std::endl;
    std::cout << "armour is: " << armour << std::endl;
    std::cout << "damage done is: " << damageDone << std::endl;
    if (damageDone > 0) {
        health -= damageDone;
        return damageDone;
    }

    return 0;
}
bool Character::isDead() { return health <= 0; }
