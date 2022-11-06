//#include <iostream>
//using namespace std;
#include "Character.h"
#include <vector>
#include "Attack.h"

#ifndef _LEVEL_H_
#define _LEVEL_H_

class Level {

private: 
  vector<Character> opponents;

public: 
  void fight(Character *, Character *);
  string fightMenu(Character*);
  void attackMenu(Character*, Character*);
};


#endif