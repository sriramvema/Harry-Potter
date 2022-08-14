/*
Name: Sriram Vema
Date: 12/7/2021
File Name: Hero.cpp
Section: 11
Description: Hero file that hero class functions
*/
#include "Hero.h"

  //Name: Hero (default constructor)
  //Precondition: None
  //Postcondition: Creates a Hero object
Hero::Hero() {
    m_name = ""; // Sets private variables to base values
    m_desc = "";
    m_hp = 0;
    m_combat = 0;
    m_rarity = 0;
}
  //Name: Hero (Overloaded constructor)
  //Precondition: None
  //Postcondition: Creates a Hero object
Hero::Hero(string name, string desc, int hp, int combat, int rarity) {
    m_name = name;  // Sets private variables
    m_desc = desc;
    m_hp = hp;
    m_combat = combat;
    m_rarity = rarity;
}
  //Name: GetCombat()
  //Precondition: None
  //Postcondition: Returns the combat value of the Hero
int Hero::GetCombat() {
    return m_combat; // returns combat
}
  //Name: GetHp()
  //Precondition: None
  //Postcondition: Returns the hit points of the Hero
int Hero::GetHp() {
    return m_hp; // returns hp
}
  //Name: GetRarity()
  //Precondition: None
  //Postcondition: Returns the rarity of the Hero
int Hero::GetRarity() {
    return m_rarity; // returns rarity
}
  //Name: GetName()
  //Precondition: None
  //Postcondition: Returns the name of the Hero
string Hero::GetName() {
    return m_name; // returns name
}
  //Name: GetDesc()
  //Precondition: None
  //Postcondition: Returns the description of the Hero
string Hero::GetDesc() {
    return m_desc; // returns description
}

  //Name: SetHp()
  //Precondition: None
  //Postcondition: Sets the hp of the Hero
void Hero::SetHp(int newHp) {
    m_hp = newHp; // sets hp
}
  //Name: SetCP()
  //Precondition: None
  //Postcondition: Sets the combat value of the Hero
void Hero::SetCombat(int newCombat) {
    m_combat = newCombat; // sets combat
}

  //Name: Train()
  //Precondition: Existing Hero
  //Postcondition: Increases the combat value of the Hero by 10
void Hero::Train() {
    m_combat = m_combat + 10; //increases combat by 10
}
  //Name: Attack()
  //Precondition: Existing Hero
  //Postcondition: Displays attack details
void Hero::Attack() {

}

ostream& operator<< (ostream& os, Hero &myHero) {
  os << myHero.m_name <<" (hp:" << myHero.m_hp << " combat:" << myHero.m_combat << ")";
  return os;
}