// GameBattleRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Character.h"
#include "Wizard.h"
#include "Knight.h"
#include "Babarian.h"
#include "Rogue.h"
#include "DemonKing.h"
#include "Enemy.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Character* creatCharacter(string userName, int userJob) {
    Character* hero;
    switch (userJob)
    {
        case 1:
            hero = new Knight(userName, "Knight", 1, 0, 4, 4, 110, 110);
            break;
        case 2:
            hero = new Wizard(userName, "Wizard", 1, 0, 5, 3, 100, 100);
            break;
        case 3:
            hero = new Babarian(userName, "Babarian", 1, 0, 3, 5, 120, 120);
            break;
        case 4:
            hero = new Rogue(userName, "Rogue", 1, 0, 5, 4, 100, 100);
            break;
        case 5:
            hero = new DemonKing(userName, "DemonKing", 1, 0, 999, 999, 999, 999);
            break;
        default:
            cout << "Please choose your job" << endl;
            return nullptr;
    }
    hero->printInfo();
    cout << "Name: " << hero->getName() << ", Job: " << hero->getJob() << " created." << endl;
    return hero;
}

Character* loadCharacter(){
    Character* loadedChar;
    string charName, charJob;
    int charLevel, charEXP, charAtt, charDef, charHP, charmaxHP;
    string line;
    ifstream loadFile;
    loadFile.open("character.txt");
    if (loadFile.is_open()){
            getline(loadFile, line);
            stringstream ss(line);
            ss >> charName >> charJob >> charLevel >> charEXP >> charAtt >> charDef >> charHP >> charmaxHP;
        
            if (charJob == "Knight"){
                loadedChar = new Knight(charName, charJob, charLevel, charEXP, charAtt, charDef, charHP, charmaxHP);
            }
            else if (charJob == "Wizard"){
                loadedChar = new Wizard(charName, charJob, charLevel, charEXP, charAtt, charDef, charHP, charmaxHP);
            }
            else if (charJob == "Babarian"){
                loadedChar = new Babarian(charName, charJob, charLevel, charEXP, charAtt, charDef, charHP, charmaxHP);
            }
            else if (charJob == "Rogue"){
                loadedChar = new Rogue(charName, charJob, charLevel, charEXP, charAtt, charDef, charHP, charmaxHP);
            }
            else if (charJob == "DemonKing"){
                loadedChar = new DemonKing(charName, charJob, charLevel, charEXP, charAtt, charDef, charHP, charmaxHP);
            }
            else {
                cout << "Invalid!!!" << endl;
                return nullptr;
            }
    }
    else {
        cout << "Cannot open file." << endl;
        loadFile.close();
        return nullptr;
    }
    if (loadCharacter != nullptr){
        loadedChar->printInfo();
        cout << "Name: " << loadedChar->getName() << ", Job: " << loadedChar->getJob() << " loaded." << endl;
        loadFile.close();
        return loadedChar;
    }
    else {
        cout << "Not load character." << endl;
        loadFile.close();
        return nullptr;
    }
}


int main()
{
    const int inputExp = 50; //Custom exp that you want
    while (true){
        // MENU
        Character* yourChar;
        Enemy enemy;
        string start, userName;
        int userJob;
        int option;
        cout << "==========WELCOME TO GOBLIN SLAYER==========" << endl;
        cout << "Enter \"start\" to play and \"exit\" to exit game." << endl;
        cin >> start;
        if (start == "exit"){
            break;
        }
        
        cout << "1 New Game" << endl;
        cout << "2 Load Game" << endl;
        cout << "3 Exit Game" << endl;
        cin >> option;
        if (option == 1){
                //Create new character
                cout << "Please enter your character name: ";
                cin >> userName;
                cout << "Please choose the number for your character's class:" << endl;
                cout << "1 Knight   2 Wizard   3 Babarian   4 Rogue" << endl;
                cin >> userJob;
                cout << "----------|| CHARACTER CREATING ||----------" << endl;
                yourChar = creatCharacter(userName, userJob);
                cout << "============================================" << endl;
                cout << endl;
            }
        else if (option == 3){
            break;
        }
        else if (option == 2){
            yourChar = loadCharacter();
            cout << endl;
            cout << endl;
        }
        else continue;

        //BATTLE !!!
    
         while (true){
            while (true){
                cout << "FINDING GOBLIN ~~~~~~~~~~" << endl;
                cout << "YOU FOUND THE GOBLIN!!!" << endl;
                enemy.printEnemy();
                int choice;
                cout << "Do you want to attack or flee? 1 Attack 2 Flee 3 Exit" << endl;
                cin >> choice;
                cout << endl;
                if (choice == 2){
                    cout << endl;
                    enemy.updateEnemy();
                    continue;
                }
                else if (choice == 1){
                    while(true){ 
                        cout << yourChar->getName() << " use " << yourChar->getSkill() << " deal " << yourChar->getDamage() << " to enemy" << endl;
                        enemy.setHP(enemy.getHP() - yourChar->getDamage() - yourChar->getAttack());
                        if (enemy.getHP() <= 0){
                            enemy.setHP(0);
                        }
                        cout << "Enemy HP: " << enemy.getHP() << " / " << enemy.getmaxHP() << endl;
                        if (enemy.getHP() <= 0){
                            cout << "Goblin defeated." << endl;
                            cout << "You gained " << inputExp << " exp." << endl;
                            cout << endl;
                            cout << "============================================" << endl;
                            cout << endl;
                            enemy.updateEnemy();
                            yourChar->UpdateLevel(inputExp);
                            if (yourChar->getExp() >= 100){
                                yourChar->levelUp();
                                cout << "################# LEVEL UP ################" << endl;
                                cout << "----- " << yourChar->getName() << " is now LEVEL " << yourChar->getLevel() << " -----" << endl;
                                yourChar->UpdateStats();
                                yourChar->setExp(0);
                                yourChar->printInfo();
                                cout << "============================================" << endl;
                                break;
                            }
                            break;
                        }
                        else {
                            string usePotion;
                            cout << "Enemy attacked deal " << enemy.getAttack() << " damage." << endl;
                            yourChar->setHP(yourChar->getHP() + yourChar->getDef() - enemy.getAttack());
                            if (yourChar->getHP() > yourChar->getmaxHP()){
                                yourChar->setHP(yourChar->getmaxHP());
                            }
                            cout << "Your HP: " << yourChar->getHP() << " / " << yourChar->getmaxHP() << endl;
                            //Your character defeated
                            if (yourChar->getHP() == 0){
                                yourChar->rest(yourChar->getHP());
                                cout << "!!!YOU ARE DEFEATED!!!" << endl;
                                cout << "============================================" << endl;
                                break;
                            }
                            //Using potion
                            cout << "Do you want to use potions? Enter \"yes\" to use, \"no\" to continue the battle." << endl;
                            cin >> usePotion;
                            cout << endl;
                            if (usePotion == "yes"){
                                yourChar->usingPotions();
                                cout << "Healed !!!" << endl;
                                cout << "Your HP: " << yourChar->getHP() << " / " << yourChar->getmaxHP() << endl;
                                cout << "============================================" << endl;
                                int healedChoice;
                                cout << "Do you want to continue attack or flee to next enemy? 1 Attack 2 Flee" << endl;
                                cin >> healedChoice;
                                cout << "============================================" << endl;
                                if (healedChoice == 2){
                                    break;
                                }
                                else continue;
                            }
                            else if (usePotion == "no"){
                                continue;
                            }
                        }
                    }
                }
                else if (choice == 3){
                    break;
                }
            }
            //Take rest for heal max HP & continue or save & exit
            int choice;
            cout << "Do you want to take rest and continue? 1 Rest & Continue 2 Save & Exit" << endl;
            cin >> choice;
            cout << endl;
            if (choice == 1){
                cout << yourChar->getName() << " has full HP now." << endl;
                yourChar->rest(yourChar->getHP());
                cout << "============================================" << endl;
            }
            else if (choice == 2){
                ofstream saveFile("character.txt");
                saveFile << yourChar->getName() << " " << yourChar->getJob() << " " << yourChar->getLevel() << " " << yourChar->getExp() << " " << yourChar->getAttack() << " " << yourChar->getDef() << " " << yourChar->getHP() << " " << yourChar->getmaxHP() << " " << yourChar->getSkill() << " " << yourChar->getDamage();
                cout << "============================================" << endl;
                cout << "            !!!CHARACTER SAVED!!!            " << endl;
                cout << "============================================" << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                return 0;
            }
            else {
                break;
            }
        }
        delete yourChar;
    }
    return 0;
}
