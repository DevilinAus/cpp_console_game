#include <cstdlib>
#include <iostream>
#include <vector>

#include "Character.h"
#include "Items.h"
#include "Text.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

const char CLEAR_SCREEN[] = "\033[2J\033[H";

// TODO move these into their own files and add to header files and then delete
void battleLoop(Character& player, Character& enemy);
void renderScreen(const string& actionText, const string& statusText, bool isDead);

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

Character characterSetup() {
    string playerName;

    cout << "What is your name?\n";
    getline(cin, playerName);
    Character player(playerName, 100, 20);
    cout << CLEAR_SCREEN;
    cout << "Welcome " << player.getName() << "!\n";
    cin.get();

    return player;
}

// GAMELOOP

void gameLoop(Character& player, vector<Item>& inventory) {
    int gameStep = 0;
    int totalStep = 100;

    string lastInput;
    getline(cin, lastInput);

    Character enemy("Goblin", 100, 20);

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

            case 2:

                battleLoop(player, enemy);
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

    Character player = characterSetup();

    gameLoop(player, inventory);
}

// Item
//   - id
//        Weapon +damage
//           addBonusDmg()
//        Armour +armour
//           takeDamage()
//        Potion onUse()

// Equipable
//   equip()
//   bool isEquipped

// HasPassiveEffect
//   bool inCombat true
//   applyBuff()

// class Potion(1234, ) : HasPassiveEffect

// class ArmourWithAffect () :

/*


// START LOOP

// player prompted for input
// calculate action
// diplay output of action

// enemy(s) decides next action (invisible)
// calculate action
// diplay output of action

// LOOP TO START



// player prompted for input again


======================================================
A wild Goblin appeared!

Goblin has 12 health remaining




Chose what to do:
1. ATTACK      2. SPELL      3. ITEM.       4. RUN
1 (ENter)
======================================================

======================================================
You hit goblin for 3 Damage.      [action text]

Goblin has 9 health remaining.    [status text]



1. ATTACK      2. SPELL      3. ITEM.       4. RUN
1 (ENter)




*/

void battleLoop(Character& player, Character& enemy) {
    string lastInput;
    string actionText = "A wild Goblin appears!";

    while (true) {
        if (lastInput == "4") {
            break;
        }

        // calculate the action
        if (lastInput == "1") {
            int playerDamage = player.attack(enemy);

            actionText =
                "You hit " + enemy.getName() + " for " + std::to_string(playerDamage) + "!";
        }

        // figureout what the actiontext is
        // You hit goblin for 3 Damage.      [action text]

        // figure out what the status text is

        renderScreen(actionText, enemy.getStatusText(), enemy.isDead());

        lastInput = cin.get();

        if (enemy.isDead()) {
            break;
        }
    }
}

void renderScreen(const string& actionText, const string& statusText, bool isDead) {
    // cout << CLEAR_SCREEN;
    cout << actionText << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << statusText << endl;
    cout << "" << endl;
    cout << "" << endl;

    if (isDead) {
        cout << "Enemy has died, good work!" << endl;
        return;
    }

    cout << "Next Action:" << endl;
    cout << "1. ATTACK      2. SPELL      3. ITEM.       4. RUN" << endl;
}
