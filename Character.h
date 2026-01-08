#pragma once

#include <string>

class Character {
   private:
    std::string name;
    int health;
    int attackPower;

   public:
    Character(const std::string& name, int health, int attackPower);
    // virtual ~Character();  // destructor?

    const std::string& getName() const;
    // void attack(Character& target);
    // void takeDamage(int amount);

    // bool isAlive() const;
    // const std::string& getName() const;
};
