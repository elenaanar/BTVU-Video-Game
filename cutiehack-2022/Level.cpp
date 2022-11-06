#include "Level.h"

string Level::fightMenu(Character* you) {
  string choice;
  bool validInput = true;
  do {
    cout << "FIGHT MENU:" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Item" << endl;
    cout << "3. Check Opponent Stats" << endl;
    // cout << "Choice: ";
    // FIRST INPUT PEOPLE WE GOT AN INPUT
    cout << "Pick an action: ";
    cin >> choice;
    cout << endl << endl;
    //int choiceNumber = stoi(choice);
    //cin.ignore('\n');
    //cout << choiceNumber << endl;
    validInput = true;
    
    if (choice.size() != 1) {
      validInput = false;
      cout << "Please enter 1, 2, or 3" << endl;
    } 
    //cout << choiceNumber << endl;
    else if (choice != "1" && choice != "2" && choice != "3" && choice != "4") {
      cout << "Please enter 1, 2, or 3. PLEASE" << endl;
      validInput = false;
    }
    else if (choice == "2" && you->getItems().size() == 0 ){
      cout << "You broke boy! Do somethin else" << endl << endl;
      validInput = false;
    }
  } while (!validInput);
  
  return choice;
}

void Level::attackMenu(Character* you, Character* opponent){
  vector<Attack *> yourAttacks = you->getAttacks();
  bool validInput = true;
  string choice;
  string newline;
  //take in user choice for attack/ error handling
  do {
    //prints all availible attacks
    cout << "Your Attacks:" << endl;
    for (unsigned i = 0; i < yourAttacks.size(); i++) {
      //only prints available ones out of vector
      if(yourAttacks.at(i)->isAvailable(you->getEnergy())){
        std::cout << "TIER " << i << ' ' << yourAttacks.at(i)->getName() << endl;
      }
    }
    //take in another choice
    std::cout << "Pick a TIER: ";
    cin >> choice;
    //if invalide choice
    if (choice.size() != 1) {
      cout << "Is that the tier number? Try again." << endl << endl;
      validInput = false;
    }
    else if(choice != "0" && choice != "1" && choice != "2"){
        cout << "Is that the tier number? I don't think so. Try again." << endl << endl;
        validInput = false;
    }
    else{
        validInput = true;
    }
  } while (!validInput);
  int choiceNum = choice.at(0) - 48;
    cout << "You used " << yourAttacks.at(choiceNum)->getName() << '!' << endl;
    //total attack strength for this turn is your strength times the attack's strength mult
    int atkStr = you->getStrength() * yourAttacks.at(choiceNum)->getStrMlt();
    //reducing opponents health
    opponent->setHealth(opponent->getHealth()-(atkStr));
    if(choiceNum == 1){
      you->setEnergy((you->getEnergy() - you->getEnergyCoef() / 2));
    }
    else if(choiceNum == 2){
      you->setEnergy((you->getEnergy() - you->getEnergyCoef() / 2 - you->getEnergyCoef()));
    }
}

void Level::fight(Character *you, Character *opponent) {
  bool validInput = true;
  string choice;
  //beginning fight
  cout << endl;
  std::cout << opponent->getName() << " STROLLS ONTO THE SCENE!" << endl << endl;
  cout << "FIGHT!" << endl << endl;
  int rndcntr = 0;
  //fight happens while both apponents are alive
  while (you->alive() && opponent->alive()) {
    ++rndcntr;
    cout << "ROUND " << rndcntr << '!' << endl << endl;
    cout << "ENERGY: " << you->getEnergy() << endl;
    string choice = fightMenu(you);
    //fight time
    if (choice == "1") {
      //menu for choosing attacks
      attackMenu(you, opponent);
      if(opponent->getHealth() <= 0){
        cout << "YOU WIN!" << endl;
        break;
      }
      //makes opponents decision: -1 if healing self, 0 for tier 0, and so on
      
    }
    //FIXME 
    else if (choice == "2"){
      // use item
      cout << "_____INVENTORY_____" << endl;
      // //FIXME
      // for (unsigned i = 0; i < ){
      // }
    }
    else if (choice == "3") {
      // check opponent stats
      cout << "You are fighting " << opponent->getName() << endl;
      cout << opponent->getName() << "'s health: " << opponent->getHealth() << endl;
      cout << opponent->getName() << "'s description: " << opponent->getDesc() << endl;
      cout << opponent->getName() << "'s strength: " << opponent->getStrength() << endl;
    } else if (choice == "4") {
      cout << "You hit 4! time to die" << endl;
      you->Die();
      break;
    }
    //increment energy for you and opponent
    you->incEnergy();
    opponent->incEnergy();
    if (you->getEnergy() > 100){
      you->setEnergy(100);
    }
    if(opponent->getEnergy() > 100){
      opponent->setEnergy(100);
    }
    int oppDec = opponent->makeDecision();
    if (oppDec == -1){
        cout << opponent->getName() << " healed themself! Their health is now: " << opponent->getHealth() << endl << endl;
      }
      else if(oppDec != -1){
        vector<Attack*> oppAttacks = opponent->getAttacks();
        int atkStr = opponent->getStrength() * oppAttacks.at(oppDec)->getStrMlt();
        //reducing opponents health
        you->setHealth(you->getHealth()-(atkStr));
        cout << opponent->getName() << " just used " << oppAttacks.at(oppDec)->getName() << ", a TIER " <<  oppDec << " attack" << endl << endl;
        if(oppDec == 1){
          opponent->setEnergy((opponent->getEnergy() - opponent->getEnergyCoef() / 2));
        }
        else if(oppDec == 2){
          opponent->setEnergy((opponent->getEnergy() - opponent->getEnergyCoef() / 2 - opponent->getEnergyCoef()));
        }
        if (you->getHealth() < 0){
          you->setHealth(0);
        }
        if (opponent->getHealth() < 0){
          opponent->setHealth(0);
        }
        cout << "YOUR HEALTH: " << you->getHealth() << endl;
        cout << opponent->getName() << "'s HEALTH: " << opponent->getHealth() << endl;
        cout << "________________________________________" << endl << endl;
     }
    
  }
}

