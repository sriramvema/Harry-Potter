/*
Name: Sriram Vema
Date: 12/7/2021
File Name: Villain.cpp
Section: 11
Description: Villain file that villain class functions
*/
#include "Villain.h"

  //Name: Villain (default constructor)
  //Precondition: None
  //Postcondition: Creates a Villain wizard object
Villain::Villain() {
    m_name = "";  // Sets private variables to default values
    m_desc = "";
    m_hp = 0;
    m_combat = 0;
    m_rarity = 0;
}
  //Name: Villain (Overloaded constructor)
  //Precondition: None
  //Postcondition: Creates a Villian wizard object
Villain::Villain(string name, string desc, int hp, int combat, int rarity) {
    m_name = name;
    m_desc = desc; // Sets private variables
    m_hp = hp;
    m_combat = combat;
    m_rarity = rarity;
}
  //Name: GetCombat()
  //Precondition: None
  //Postcondition: Returns the combat value of the Villain wizard
int Villain::GetCombat() {
    return m_combat; // returns combat
}
  //Name: GetHp()
  //Precondition: None
  //Postcondition: Returns the hit points of the Villain wizard
int Villain::GetHp() {
    return m_hp; // returns hp
}
  //Name: GetRarity()
  //Precondition: None
  //Postcondition: Returns the rarity of the Villain wizard
int Villain::GetRarity() {
    return m_rarity; // returns rarity
}
  //Name: GetName()
  //Precondition: None
  //Postcondition: Returns the name of the Villain wizard
string Villain::GetName() {
    return m_name; // returns name
}
  //Name: GetDesc()
  //Precondition: None
  //Postcondition: Returns the description of the Villain wizard
string Villain::GetDesc() {
    return m_desc; // returns description
}

  //Name: SetHp()
  //Precondition: None
  //Postcondition: Sets the hp of the Villain
void Villain::SetHp(int newHp) {
    m_hp = newHp;
}
  //Name: SetCombat()
  //Precondition: None
  //Postcondition: Sets the combat value of the Villain
void Villain::SetCombat(int newCombat) {
    m_combat = newCombat;
}
  //Name: Attack()
  //Precondition: Existing Villain
  //Postcondition: Displays attack details
void Villain::Attack() {
  
}

ostream& operator<< (ostream& os, Villain &myVillain) {
  os << myVillain.m_name <<" (hp:" << myVillain.m_hp << " combat:" << myVillain.m_combat << ")";
  return os;
}