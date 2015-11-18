#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "main.h"
#include "Fight.h"
using namespace std;
void fight()
{
    cout << "You arrive in a grassy plain. A rat blocks your path. You must fight." << endl;
    battle = true; // battle happens so it becomes true
    player->reinitialize();
    enemy->reinitialize();
    while(battle) // fight happens until it becomes false
    {
        cout << "Battle stats:" << endl;
        cout << "Your health: " << player->currenthealth << "/" << player->health << endl;
        cout << "Enemy health " << enemy->currenthealth << "/" << enemy->health << endl;
        cout << "What will you do?" << endl << "1: Attack" << endl << "2: Do Nothing" << endl;
        cin >> response;
        switch(response)
            {
                case 1:
                    cout << "You attack! Rat takes " << player->damage << " damage!" << endl;
                    enemy->getAttacked(player);
                    if(enemy->currenthealth <= 0)
                    {
                        battle = 0; // battle stops when enemy dies
                        victory = 1; //player wins, victory is true
                        continue;
                    }
                    break;
                case 2:
                    cout << "You do nothing!" << endl;
                    break;
                default:
                    cout << "No action corresponds with that number. Try again!" << endl;
                    continue;
                    break;
            }
        cout << "Rat attacks you for " << enemy->damage << " damage!" << endl;
          enemy->attack(player);
        if(player->currenthealth <= 0)
        {
            battle = 0; //battle stops when player dies
            victory = 0;//player loses, victory is false
        }
    }
    if(victory)
    {
        cout << "U win gj, U get " << enemy->xp << " experience points!" << endl;
    }
    else
    {
        cout << "U lose gj." << endl;
    }
    return;
}