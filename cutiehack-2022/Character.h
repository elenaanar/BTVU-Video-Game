// #include <iostream>
#include <vector>
//using namespace std;
#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include "Item.h"
#include "Attack.h"

class Character {
private:
  string name;
  string description;
  int health;
  int energy;
  vector<Item*> items;
  vector<Attack*> attacks;
  int strength;
  int money;
  int energyCoef;

public:
  Character();
  Character(string name, string desc, int health, int energy, int strength,
  int money, int energyCoef);
  // getters
  string getName() const;
  string getDesc() const;
  int getHealth() const;
  int getEnergy() const;
  int getStrength() const;
  int getMoney() const;
  vector<Item*> getItems() const;
  vector<Attack*> getAttacks() const;
  bool alive() const;
  int getEnergyCoef() const;
  // setters
  void setName(string);
  void setHealth(int);
  void setDesc(string);
  void setEnergy(int);
  void setStrength(int);
  void setMoney(int);
  void addItem(Item*);
  void addAttack(Attack*);
  void incEnergy();
  bool alive();
  void Die();
  void setEnergyCoef(int);
  // fight func
  void fight(Character *);
  string menu();
  int makeDecision();
};

#endif