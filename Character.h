#pragma once

#include <string>

class Character {
   private:
    std::string name;
    int attackPower;
    int health;

   public:
    Character(const std::string& name, int health, int attackPower);
    // virtual ~Character();  // destructor?

    const std::string& getName() const;
    const std::string& getStatusText() const;
    int takeDamage(int damage);
    int attack(Character& enemy);
    bool isDead();

    // void attack(Character& target);
    // void takeDamage(int amount);

    // bool isAlive() const;
    // const std::string& getName() const;
};
