#include "Items.h"

#include <vector>

int loadDagger(std::vector<Item>& inventory) {
    Item dagger;
    dagger.name = "Dagger";
    dagger.type = "weapon";
    dagger.damageBonus = 1;

    inventory.push_back(dagger);
    return 0;
}
