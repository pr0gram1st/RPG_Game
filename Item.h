//
// Created by Adilet Kemelkhan on 13.09.2021.
//

#ifndef L1_IT_2003_4_MAIN_ITEM_H
#define L1_IT_2003_4_MAIN_ITEM_H
class Item{
public:
    Item(){
        this->name = ".";
        this->price = 0;
    }
    Item(string name, int price){
        this->name = name;
        this->price = price;
    }
    int getPrice(){
        return this->price;
    }
    void toString(){
        cout << "Name: " << this->name << endl;
        cout << "Price: " << this->price << endl;
    }
    string getName(){
        return this->name;
    }
private:
    string name;
    int price;
};
#endif //L1_IT_2003_4_MAIN_ITEM_H
