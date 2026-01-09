#include <string>
#include <vector>

struct Item {
    std::string name;
    std::string type;
    int damageBonus;
    int armorBonus;
    int healAmount;
    int usesRemaining;
};

int loadDagger(std::vector<Item>& inventory);