#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include "Enemy.h"
#include "main.h"
#include "player.h"
using namespace std;
int response; //variable for handling user response
bool battle; // is battle happening
bool victory; // win a battle or not
int location = 0; // determines which menu (shop, battle, etc) to display
/* 0 = crossroads
 * 1 = shop
 * 2 = battle
 */
Enemy* enemy = new Enemy();
Player* player = new Player();
void intro()
{
    cin >> response;
    if(response == 1)
    {
        cout << "No save file ok. You've already caught on to the method of gameplay. To perform the desired action, type the number beforehand." << endl << "That's all you need to know, now go on a great text-based adventure!" << endl;
    }
    else if(response == 2)
    {
        cout << "No save file ok. You've already caught on to the method of gameplay. To perform the desired action, type the number beforehand." << endl << "That's all you need to know, now go on a great text-based adventure!" << endl;
    }
    else
    {
     cout << "No action corresponds with that number. Try again!" << endl;
     intro();
    }            
}
void crossroads()
{
    cout << "Where will you go?" << endl;
    cout << "1: Shop" << endl << "2: Battle" << endl;
    cin >> response;
    location = response;
}
void shop()
{
    cout << "Shop doesn't exist yet." << endl;
    location = 0;
}
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
                        location = 0;
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
            location = 0;
        }
    }
    if(victory)
    {
        cout << "U win gj, U get " << enemy->xp << " experience points!" << endl;
        cout << "You get " << enemy->goldDropped << " gold!" << endl;
        
    }
    else
    {
        cout << "U lose gj." << endl;
    }
    cout << "After a hard battle, you return home to rest. Wake up the next day ready to take on the day!" << endl;

    return;
}
int main()
{
    cout << "Welcome to the Text Based Adventure Game! Do you have a saved game?" << endl;
    cout << "1: Yes" << endl << "2: No" << endl;
    intro();
    while(1)
    {
        if(location == 0)
        {
            crossroads();
        }
        else if(location == 1)
        {
            shop();
        }
        else if(location == 2)
        {
            fight();
        }
    }
}