#include "Attack.h"

Attack::Attack(){
  Item();
  available = false;
  energyNeeded = 0;
  strMlt = 0;
}

Attack::Attack(string name, string desc, int healthChanged, int energyNeeded){
  this->name = name;
  this->description = desc;
  this->healthChanged = healthChanged;
  this->energyNeeded = energyNeeded;
  if (energyNeeded >= 60){
    strMlt = 4;
    this->available = false;
  }
  else if (energyNeeded <= 60 && energyNeeded >= 20){
    strMlt = 2;
    this->available = false;
  }
  else {
    strMlt = 1;
    this->available = true;
  }
}

bool Attack::isAvailable(int energy){
  if(energy >= energyNeeded){
    available = true;
  }
  else
    available = false;
  return available;
}

int Attack::getEnergyNeeded() const{
  return energyNeeded;
}

void Attack::setEnergyNeeded(int energyNeeded){
  this->energyNeeded = energyNeeded;
}
int Attack::getStrMlt() const{
  return strMlt; 
}
