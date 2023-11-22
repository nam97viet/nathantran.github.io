#include <iostream>
#include <cstdlib>
#include "time.h"

#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
  Enemy() {
    // Generate random HP and attack values
    maxHP = rand() % 50 + 1;
    attack = rand() % 10 + 1;
    hp = maxHP;
  }
  ~Enemy(){}

  // Getters for HP and attack
  int getmaxHP() { return this->maxHP; }
  int getHP() { return this->hp; }
  int getAttack() { return this->attack; }

  void setHP (int enemyHP){
    this->hp = enemyHP;
  }

  void printEnemy(){
    cout << "HP: " << getHP() << endl;
    cout << "Attack: " << getAttack() << endl;
    cout << endl;
  }

  void updateEnemy(){
    srand(time(NULL));
    maxHP = rand() % 50 + 1;
    attack = rand() % 10 + 10;
    hp = maxHP;
  }

private:
  // HP and attack values
  int maxHP;
  int hp;
  int attack;
};

#endif