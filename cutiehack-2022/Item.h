#ifndef __ITEM_H
#define __ITEM_H

#include <iostream>

using namespace std;

class Item{
protected:
  string name, description;
  int healthChanged, price;
public:
  Item();
  Item(string, string, int, int);
  string getName() const;
  void setName(string);
  string getDescription() const;
  void setDescription(string);
  int getHealthChanged() const;
  void setHealthChanged(int);
  int getPrice() const;
  void setPrice(int);
};

#endif