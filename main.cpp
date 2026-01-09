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
using std::vector;

const char CLEAR_SCREEN[] = "\033[2J\033[H";

// MENU

void menuLoop() {
    string lastInput;
    cout << CLEAR_SCREEN;
    cout << "1. Inventory\n";
    cout << "2. Loadout \n";
    cout << "3. Save \n";
    cout << "4. Back\n";
    getline(cin, lastInput);

    while (true) {
        if (lastInput == "1" || lastInput == "inventory") {
            cout << "inventoryMenu()";
        }

        if (lastInput == "2" || lastInput == "equipment") {
            cout << "equipmentMenu()";
        }

        if (lastInput == "3" || lastInput == "save") {
            cout << "save()";
        }

        if (lastInput == "4" || lastInput == "back") {
            cout << CLEAR_SCREEN;
            break;
        }
        cout << CLEAR_SCREEN;
        cout << "1. Inventory\n";
        cout << "2. Loadout \n";
        cout << "3. Save \n";
        cout << "4. Back\n";
        getline(cin, lastInput);
    }
}

// CHARACTER SETUP

void characterSetup() {
    string playerName;

    cout << "What is your name?\n";
    getline(cin, playerName);
    Character player(playerName, 100, 20);
    cout << CLEAR_SCREEN;
    cout << "Welcome " << player.getName() << "!\n";
    cin.get();
}

// GAMELOOP

void gameLoop(vector<Item>& inventory) {
    int gameStep = 0;
    int totalStep = 100;

    string lastInput;
    getline(cin, lastInput);

    while (true) {
        if (lastInput == "menu") {
            menuLoop();
        }
        switch (gameStep) {
            case 0:
                cout << introText();
                gameStep++;
                break;

            case 1:
                cout << "1. Pickup Dagger \n";
                if (lastInput == "1") {
                    cout << "You add the dagger to your inventory.\n";
                    loadDagger(inventory);
                    gameStep++;
                }
                break;

            default:
                break;
        }
        getline(cin, lastInput);

        // cout << "A goblin appears from the bushes infront of you\n He attacks!\n";
    }
}

// COMBAT

// void combatLoop() {}

int main() {
    vector<Item> inventory;

    cout << "Push Any Key To Start\n";
    cin.get();

    cout << CLEAR_SCREEN;

    characterSetup();

    gameLoop(inventory);
}