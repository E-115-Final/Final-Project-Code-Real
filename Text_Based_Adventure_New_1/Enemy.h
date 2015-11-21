#ifndef __Enemy_H_INCLUDED__
#define __Enemy_H_INCLUDED__
#include "Player.h"
class Enemy
{
public:
  int xp;
  int health;
  int currenthealth;
  int defense;
  int goldDropped;
  int damage;
  int runChance;
  void attack(Player* p);
  void getAttacked(Player* p);
  void reinitialize();
  Enemy()
  {
      xp = 10;
      health = 50;
         currenthealth = health;
      defense = 0;
      damage = 1;
  }
  
};
#endif