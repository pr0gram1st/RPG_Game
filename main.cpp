//Develop text-based RPG game:
//Classes: Item, Character, Game
//Item: name, price, damage
//Character: name, HP, maxHP, Atk, Level, exp
//Enemy:
//Game: mainMenu(), int option (for menu), bool playing
#include <iostream>
#include "Game.h"

int main() {
    Game game;

    while (game.isPlaying()) {
        game.mainMenu();
    }
    //cout << "Hello, World!" << endl;
    return 0;
}
