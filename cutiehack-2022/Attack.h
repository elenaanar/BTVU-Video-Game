#ifndef __ATTACK_H
#define __ATTACK_H

#include "Item.h"

class Attack : public Item{
private:
  bool available;
  int energyNeeded;
//strength multiplier
  int strMlt;

public:
  Attack();
  Attack(string, string, int, int);
  bool isAvailable(int);
  void setEnergyNeeded(int);
  int getEnergyNeeded() const;
  int getStrMlt() const;
  void setStrMlt(int);
};

#endif