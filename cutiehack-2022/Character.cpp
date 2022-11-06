#include <iostream>
using namespace std;
#include "Character.h"
#include "Item.h"
#include <vector>
#include <stdlib.h>
//#include <cstdlib>

Character::Character() {
  name = "Untitled Character";
  description = "Empty desc";
  health = 0;
  energy = 0;
  strength = 0;
  money = 0;
}

Character::Character(string name, string desc, int health, int energy, int strength, int money, int energyCoef): name(name), description(desc), health(health), energy(energy), strength(strength), money(money), energyCoef(energyCoef){}
string Character::getName() const { return name; }
string Character::getDesc() const { return description; }
int Character::getHealth() const { return health; }
int Character::getEnergy() const { return energy; }
int Character::getStrength() const { return strength; }
int Character::getMoney() const { return money; }
vector<Item *> Character::getItems() const { return items; }
vector<Attack *> Character::getAttacks() const { return attacks; }


void Character::setName(string name) { this->name = name; }
void Character::setDesc(string desc) { this->description = desc; }
void Character::setEnergy(int energy) { this->energy = energy; }
void Character::setStrength(int strength) { this->strength = strength; }
void Character::setMoney(int money) { this->money = money; }
void Character::Die(){ this->health = 0; }
void Character::addItem(Item *newItem) { items.push_back(newItem); }
void Character::addAttack(Attack* newAttack) { attacks.push_back(newAttack); }

bool Character::alive() {
  if (this->health > 0) {
    return true;
  }
  return false;
}

void Character::incEnergy(){
  this->setEnergy(this->getEnergy() + this->getEnergyCoef());
}

void Character::setHealth(int newHealth){
  this->health = newHealth;
}

//NEVER CALL THIS FUNCTION FOR TY UNTIL WE HAVE OTHER PLAYABLE CHARACTERS
int Character::makeDecision(){
    if(health < 10){
        srand(time(0));
        int i = (rand() % 100);
        if(i >= 70){
            health += 15;
            return -1;
        }
    }
    if(energy < 20){
        //tier 0 attack only
        return 0;
    }
    else if(energy < 60){
         //choose between tier 0 and tier 1
         srand(time(0));
        int i = rand() % 100;
        if(i >= 60)
            //choose tier 1 attack
            return 1;
        else //choose tier 0
            return 0;
    }
    else{
        srand(time(0));
        int i = rand() % 100;
        if(i >= 80)
            //choose tier 2
            return 2;
        else if(i >= 50)
            //choose tier 1
            return 1;
        else
            // choose tier 0
            return 0;
        //choose between tier 0, tier 1, and tier 2
    }
}

void Character::setEnergyCoef(int energyCoef){
  this->energyCoef = energyCoef;
}

int Character::getEnergyCoef() const{
  return this->energyCoef;
}






