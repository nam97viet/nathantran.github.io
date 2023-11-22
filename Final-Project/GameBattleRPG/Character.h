#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
    private:
        string name;
        string job;
        int level;
        int exp;
        int attack;
        int def;
        int hp;
        int maxHP;
    public:
    //Contructor
    Character(){}
    Character(string name, string job, int level, int exp, int attack, int def, int hp, int maxHP) {
        this->name = name;
        this->job = job;
        this->level = level;
        this->exp = exp;
        this->attack = attack;
        this->def = def;
        this->hp = hp;
        this->maxHP = maxHP;
    }
    
    //Destructor
    virtual ~Character(){}

    //Accessor
    string getName() { return this->name; }
    string getJob() { return this->job; }
    int getLevel() { return this->level; }
    int getExp() { return this->exp; }
    int getAttack() { return this->attack; }
    int getDef() { return this->def; }
    int getHP() { return this->hp; }
    int getmaxHP() { return this->maxHP; }
    virtual string getSkill() = 0;
    virtual int getDamage() = 0;

    //Mutator
    void setName(string name){
        this->name = name;
    }
    void setJob(string job){
        this->job = job;
    }
    void setLevel(int level){
        this->level = level;
    }
    void setExp(int exp){
        this->exp = exp;
    }
    void setAttack(int attack){
        this->attack = attack;
    }
    void setDef(int def){
        this->def = def;
    }
    void setHP(int hp){
        this->hp = hp;
    }
    void setmaxHP(int maxHP){
        this->maxHP = maxHP;
    }
    

    //Print character info
    virtual void printInfo(){}

    //Using potion to recover hp
    void usingPotions()
    {
        hp += 10;
        if (hp >= maxHP){
            hp = maxHP;
        }
    }

    //Get rest to recover full heath
    int rest(int currHP)
    {
        currHP = maxHP;
        hp = currHP;
        return hp;
    }

    //Update character when level up
    void UpdateLevel(int inputExp) {
        this->exp = this->exp + inputExp;
    }
    void levelUp(){
        this->level += 1;
    }
    void UpdateAttack(int attGain) { attack += attGain; }
    void UpdateDefense(int defGain) { def += defGain; }
    void UpdateHp(int hpGain)
    { 
        maxHP += hpGain;
        hp = maxHP;
    }
    virtual void UpdateStats(){}

       

};

#endif
