#include "main.h"
#include "Enemy.h"
#include "Player.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>  
using namespace std;
void Enemy::attack(Player* p)
{
    p->currenthealth-=damage;
}
void Enemy::getAttacked(Player* p)
{
    currenthealth-=p->damage;
}
void Enemy::reinitialize()
{
    xp = 10;
    health = 50;
    currenthealth = health;
    defense = 0;
    damage = rand() % 15 + 10;
}