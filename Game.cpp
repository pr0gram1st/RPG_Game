#include "Game.h"
#include "Character.h"
#include "Item.h"

Game::Game(){
    option = 0;
    playing = true;
    //some code
}

void Game::mainMenu() {
    srand(time(NULL));
    cout<<"Main menu"<<endl<<endl;
    cout<<"1. Start"<<endl;
    cout<<"0. Quit"<<endl<<endl;

    cout<<"Choose option: "<<endl;
    cin>>option;
    switch (option) {
        case 1:
            cout<<"1. Create character"<<endl;
            cout<<"0. Quit"<<endl;
            int option2;
            cin >> option2;
            if(option2 == 1){
                string name;
                int maxHP, Atk;
                cout << "Enter character's name: ";
                cin >> name;
                cout << "Enter character's max HP: ";
                cin >> maxHP;
                cout << "Enter character's damage: ";
                cin >> Atk;
                Character ch1 = Character(name, maxHP, Atk);
                cout << "Your opponent is: \n";
                Character ch2 = Character("Bob", 100, 10);
                ch2.showStats();
                int cnt = 0;
                string sozder1[] = {": Sorry Bob... Nothing personal, just business!", ": I gave birth to you, I will kill you", ": I will tell your family that you loved them", ": I am your father!"};
                string sozder2[] = {": It's ok, I understand....", ": I forgive you...\n(reference to the SM3 Tobey Maguire)", ": Hey dude, it hurts!", ": Isn't it boring for you just kicking me?!?!?!?!"};
                cout << "Let's Start GAME!\n";
                while(true){
                    if(cnt != 0){
                        cout << "------------------------CHAT------------------------\n";
                        int chh = rand() % 2 + 1;
                        if(chh == 1){
                            cout << name << sozder1[rand() % 4] << endl;
                        }
                        else{
                            cout << "Bob" << sozder2[rand() % 4] << endl;
                        }
                    }
                    cnt++;
                    cnt %= 3;
                    cout<<"1. Hit Enemy"<<endl;
                    cout<<"0. Quit"<<endl;
                    int option3;
                    cin >> option3;
                    if(option3 == 0){
                        cout << "GAME ENDED!\n";
                        break;
                    }
                    ch2.damaged(ch1.getAtk());
                    if(!ch2.isAlive()){
                        cout << "Congratulations, you won!\n";
                        cout << "Item Dropped: \n";
                        Item x = ch2.dropRandom();
                        x.toString();
                        ch1.takeItem(x);
                        ch1.takeExp(ch2.getExp());
                        cout << "Winner information: \n";
                        ch1.showStats();
                        break;
                    }
                    ch2.showStats();
                }
            }
            else{
                playing = false;
                break;
            }
        case 0: playing = false; break;
        default: break;

    }


}

int Game::getOption() const{
    return option;
}

bool Game::isPlaying() const {
    return playing;
}