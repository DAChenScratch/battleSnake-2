//
//  Engine.h
//  GiocoLabInf
//
//  Created by Enrico Migliorini on 17/03/14.
//  Copyright (c) 2014 Enrico Migliorini. All rights reserved.
//

//==================================================//
//                                                  //
//  Engine works with the fleet and the narration    //
//                                                  //
//==================================================//

#ifndef __GiocoLabInf__Engine__
#define __GiocoLabInf__Engine__

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <stdlib.h>
#include <time.h>

#include "FleetMember.h"
#include "Graphics.h"
#include "Level.h"
#include "Enemy.h"
#include "Spaceship classes/Fighter.h"
#include "Spaceship classes/Corvette.h"
#include "Spaceship classes/Frigate.h"
#include "Spaceship classes/Destroyer.h"
#include "Spaceship classes/Cruiser.h"

using namespace std;

const int DELAY = 200;

class Engine {
public:
    Engine();
    int start();

private:
    int fleetsize;
    int enemysize;
    int score;
    int parts;
    Level currentLevel;
    
    void addFleetMember(Characters choice);
    void addEnemyFleetMember(int x, int y, Characters choice);
    Event lastTriggered;
    
    map<string, Item> inventory;
    vector<Direction> moveBuffer;
    vector<FleetMember> fleet;
    vector<Enemy> enemyFleet;   // Using the Enemy class allows me to create any kind of enemy, either alien or human or whatever, I just need to create a new class. I guess i COULD just make a better constructor.
    void fleetBuilder(Screens &lastDisplayed, Graphics graph);
    void printFleetStats();
    void moveFleetOnMap(Direction dest);
    void startLevel(int levelCode);
    void endLevel();                    // TODO; finisce la missione dopo un po'.
    
    // The functions that spawn enemies
    Characters intToCharacterConvert(int input);
    int getRandInSpan(int lower, int upper);
    void spawnEnemy(int x, int y, Level current);
    
    void killEnemy();   // TO ADJUST
    void collectParts(int amount);
    
    bool isOccupied(int x, int y, Level curr);
    
    void setLastEvent(Event last);
    Event getLastEvent();
    
    void loadEquipment();
    
    // Here I write some graphic functions that have a huge benefit from being here, namely access to the inventory, the members and remove the need to include engine in Graphics. Graphics will just need to include the most basic functions.
    // Or, now that I switched the organization, I could give them a graph and let them do their magic. Will think later.
    // Draws the whole fleet
    void drawFleet(Graphics graph);
    void drawEnemyFleet(Graphics graph);
    //Writes the selection of items. I will need many resources such as this. setView must be called on menu before this one.
    void printEquipMenu(SDL_Renderer* renderer, TTF_Font* font);
    //Writes the status menu.
    void printFleetStats(SDL_Renderer* renderer, TTF_Font* font);
    //Writes battle info. Alerts and narration just need to be printed on screen, sometimes by events.
    void printBattleInfo(SDL_Renderer* renderer, TTF_Font* font);
};

#endif /* defined(__GiocoLabInf__Engine__) */
