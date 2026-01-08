#include "Items.h"

#include <vector>

int loadDagger(std::vector<Item>& items) {
    Item dagger;
    dagger.name = "Dagger";
    dagger.type = "weapon";
    dagger.damageBonus = 1;

    items.push_back(dagger);
    return 0;
}
