#include "Item.h"

Item::Item(){
  name = "Untitled Item";
  description = "Does nothing";
  price = 0;
  healthChanged = 0;
}

Item::Item(string name, string description, int price, int healthChanged):name(name), description(description), price(price), healthChanged(healthChanged){}

string Item::getName() const{
  return name;
}

void Item::setName(string name){
  this->name = name;
}

string Item::getDescription() const{
  return description;
}

void Item::setDescription(string description){
  this->description = description;
}

int Item::getPrice() const{
  return price;
}

void Item::setPrice(int price){
  this->price = price;
}

int Item::getHealthChanged() const{
  return healthChanged;
}

void Item::setHealthChanged(int healthChanged){
  this->healthChanged = healthChanged;
}