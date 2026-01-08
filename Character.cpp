#include "Character.h"

#include <iostream>

Character::Character(const std::string& name, int health, int attackPower)
    : name(name), health(health), attackPower(attackPower) {}

const std::string& Character::getName() const { return name; }
