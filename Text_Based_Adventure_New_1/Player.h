#ifndef PLAYER_H

#define PLAYER_H
//#include "Enemy.h"


class Player {
public:
  int xp;
  int health;
  int currenthealth;
  int defense;
  int damage;
  int level;
  void reinitialize();
  //void attack(Enemy* e);
  Player()
  {
   health = 60;
   currenthealth = health;
   defense = 0;
   damage = 1;
  };

};

#endif /* PLAYER_H */