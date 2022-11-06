#include "Attack.h"
#include "Character.h"
#include "Item.h"
#include "Level.h"
#include <iostream>

using namespace std;

void instructions(){
  cout << "Welcome to BARON AND TY VERSUS THE UNIVERSE (INCLUDING THEMSELVES): THE VIDEO GAME!" << endl;
 // cout << "You will be"
}

int main() {
  //name, desc, health, energy, strength, money, energyCoef
  Character *ty = new Character("Ty", "Clown", 100, 0, 15, 10, 30);
  Attack* tyAttack0 = new Attack("Axe Attack", "Chop em down with a quick HACK!", -1, 0);
  Attack* tyAttack1 = new Attack("Axe-Nado!", "Turn into a spinning ball of slicing!", -1, 20);
  Attack* tyAttack2 = new Attack("Seeing Double", "Split your opponent in HALF!", -1, 60);
  //TY TIER 0 
  ty->addAttack(tyAttack0);
  //TY TIER 1
  ty->addAttack(tyAttack1);
  //TY TIER 2
  ty->addAttack(tyAttack2);

  // vector<Attack*> tyAttacks = ty->getAttacks();
  // for(unsigned i = 0; i < tyAttacks.size(); i ++){
  //   cout << tyAttacks.at(i)->getName() << endl;
  // }

  Character *baron = new Character("BARON VON BARON", "Captialist", 125, 0, 20, 10000, 15);
  Attack* baronAttack0 = new Attack("Batter up!", "Baron swing's his hammer for a home run!", -1, 0);
  Attack* baronAttack1 = new Attack("Free Samples", "Several objects fall from his pockes, including but not limited to: anvils, bombs, and bear traps, OH MY!", -1, 20);
  Attack* baronAttack2 = new Attack("WHAMMO!", "Baron's hammer sprouts a giant rocket. He rushes forward and brings the hammer DOWN!", -1, 60);
  //BARON TIER 0
  baron->addAttack(baronAttack0);
  //BARON TIER 1
  baron->addAttack(baronAttack1);
  //BARON TIER 2
  baron->addAttack(baronAttack2);

  // vector<Attack*> bAttacks = baron->getAttacks();
  // for(unsigned i = 0; i < bAttacks.size(); i ++){
  //   cout << bAttacks.at(i)->getName() << endl;
  // }

  Level* level1 = new Level;
  level1->fight(ty, baron);
}
