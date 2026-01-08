#include <cstdlib>
#include <iostream>
#include <vector>

#include "Character.h"
#include "Items.h"
#include "Text.h"

using std::cin;
using std::cout;
using std::getline;
using std::string;

int main() {
    // int test = 2;
    std::vector<Item> items;

    cout << "\033[2J\033[H";

    cout << "Push Any Key To Start\n";
    cin.get();
    cout << "\033[2J\033[H";

    system("clear");
    cout << "\033[2J\033[H";

    string playerName;

    cout << "What is your name?\n";
    getline(std::cin, playerName);
    Character player(playerName, 100, 20);
    cout << "\033[2J\033[H";
    cout << "Welcome " << player.getName() << "!\n";
    cin.get();
    cout << introText();
    cin.get();

    // pickup dagger.
    cout << "1. Pickup Dagger \n";

    if (cin.get() == '1') {
        cout << "You add the dagger to your inventory.";
        loadDagger(items);
    }

    // std::cout << link.getName() << "\n";
}
