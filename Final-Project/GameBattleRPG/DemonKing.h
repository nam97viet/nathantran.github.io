#include <string>
#include <iostream>
#include "Character.h"

using namespace std;

#ifndef DEMONKING_H
#define DEMONKING_H

class DemonKing: public Character
{
    private:
        string skill;
        int damage;
        int attGain;
        int defGain;
        int hpGain;
    public:
        //Contructor
        DemonKing(string name, string job, int level, int exp, int attack, int def, int hp, int maxHP) : Character(name, job, level, exp, attack, def, hp, maxHP)
        {
            skill = "Destroy";
            damage = 999;
            attGain = 0;
            defGain = 0;
            hpGain = 0;
        }
        virtual ~DemonKing(){}
        
        string getSkill() override { return this->skill; }
        int getDamage() override { return this->damage; }

        //Update Stats
        void UpdateStats() override
        {
            UpdateAttack(this->attGain);
            UpdateDefense(this->defGain);
            UpdateHp(this->hpGain);
        }

        void printInfo()
            {
                cout << "Name: " << getName() << endl;
                cout << "Job: " << getJob() << endl;
                cout << "Level: " << getLevel() << endl;
                cout << "Exp: " << getExp() << endl;
                cout << "Attack = " << getAttack() << endl;
                cout << "Defense = " << getDef() << endl;
                cout << "HP = " << getHP() << " / " << getmaxHP() << endl;
                cout << "Skill: " << getSkill() << endl;
                cout << "Damage : " << getDamage() << endl;
            }
        
};  


#endif