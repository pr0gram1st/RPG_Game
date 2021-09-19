//
// Created by Adilet Kemelkhan on 13.09.2021.
//

//Character: name, HP, maxHP, Atk, Level, exp
#include "Item.h"
#include <cstdlib>
#include <ctime>

#ifndef L1_IT_2003_4_MAIN_CHARACTER_H
#define L1_IT_2003_4_MAIN_CHARACTER_H

int lvlup = 5; //amount of experience needed to increase level

class Character {
public:
    Character(string name, int maxHP, int Atk) { //creating constructor with 3 attributes
        Item sword = Item("Sword", 100);
        this->itemsCount = 1;
        this->items[0] = sword;
        this->name = name;
        this->maxHP = maxHP;
        this->HP = maxHP;
        this->Atk = Atk;
        this->level = 1;
        this->exp = 0; //initializing starting values
    }

    Item dropRandom() { //method to drop random item from inventory
        srand(time(NULL));
        int pos = rand() % this->itemsCount;
        Item x = this->items[pos];
        for (int i = 0; i < this->itemsCount; ++i) {
            this->items[i] = Item();
        }
        this->itemsCount = 0;
        return x;
    }

    bool cmp(Item a, Item b){ //comparator to choose better item
        if(a.getPrice() > b.getPrice()){
            return true;
        }
        return false;
    }

    void takeItem(Item x){ //method to take item of your opponent
        if(this->itemsCount < 3){ //checking if we have enough items
            this->items[this->itemsCount] = x;
            this->itemsCount++;
            return;
        }
        for(int i = 0; i < 3; i++){ //if yes sorting all of them
            for(int j = i + 1; j < 3; ++j){
                if(cmp(this->items[i], this->items[j])){
                    swap(this->items[i], this->items[j]);
                }
            }
        }
        if(!cmp(this->items[2], x)){ //checking if our item is ok
            this->items[2] = x;
        }
    }

    void die() { //method to define if character is dead
        cout << "Character " << this->name << " is dead X_X\n";
        this->HP = 1;
        this->level = 1;
        this->exp = 0;
        this->life = false;
    }

    void damaged(int Atk){ //method to damage the character
        cout << "Character " << this->name << " has been damaged\n";
        this->HP -= Atk;
        if(this->HP <= 0){
            die();
        }
    }

    void takeExp(int x){ //method to gain someone's exp
        this->exp += x;
        cout << "EXP successfully gained\n";
    }

    int getExp(){ //getter
        return this->exp;
    }

    int getAtk(){ //getter
        return this->Atk;
    }

    bool isAlive(){ //getter
        return life;
    }

    void levelup() { //automatic method to rise up level of character
        int lvls = this->exp / lvlup;
        this->exp %= lvlup;
        if (lvls > 0) {
            cout << "Your new exp is: " << this->exp << endl;
            this->level += lvls;
            for (int i = 0; i < lvls; ++i) {
                cout << "Congratulations! Level UP!\n";
            }
            cout << "Your new level is: " << this->level << endl;
            this->maxHP += 5 * lvls;
            cout << "Your max HP is: " << this->maxHP << endl;
            this->HP += 5 * lvls;
            cout << "Your HP is: " << this->HP << endl;
        } else {
            return;
        }
    }
    void showStats(){ //game log
        cout << "Name: " << this->name << endl;
        cout << "HP: " << this->HP << endl;
        cout << "maxHP: " << this->maxHP << endl;
        cout << "Damage: " << this->Atk << endl;
        cout << "Level: " << this->level << endl;
        cout << "Experience: " << this->exp << endl;
        cout << "ItemsCount: " << this->itemsCount << endl;
        cout << "Items information: \n";
        for(int i = 0; i < this->itemsCount; ++i){
            Item x = this->items[i];
            x.toString();
        }
    }
private: //character attributes
    int itemsCount;
    Item items[3];
    string name;
    int HP;
    int maxHP;
    int Atk;
    int level;
    int exp;
    bool life = true;
};
#endif //L1_IT_2003_4_MAIN_CHARACTER_H
