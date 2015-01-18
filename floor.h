#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <string>
#include "cell.h"
#include "textdisplay.h"
#include <vector>

#include "character.h"
#include "human.h"
#include "orc.h"
#include "dwarf.h"
#include "elves.h"
#include "vampire.h"
#include "werewolf.h"
#include "troll.h"
#include "goblin.h"
#include "phoenix.h"
#include "merchant.h"

#include "item.h"
#include "boostatk.h"
#include "boostdef.h"
#include "restorehealth.h"
#include "poisonhp.h"
#include "woundatk.h"
#include "wounddef.h"
#include "smallhorde.h"
#include "dragonhorde.h"
#include "normal.h"
#include "merchanthorde.h"
#include <ncurses.h>

class Floor {
	bool won;	     // Grid in winning state
	TextDisplay *td;     // The text display
	std::vector<Cell*> cells;
	std::vector<Item*> potions;
	std::vector<Character*> enemies; //stores all enemies on current floor
	int floorLevel;
	Character* PChr;
    	std::string action;
   	static bool gameEnd;

public:
	Floor(std::string race);
	~Floor();
  	void resetFloor();
	static void setGameWon();
	static bool gameWon();
	void clearFloor();
	void printStats();
	void init(std::string filename);   // initiates a new floor
	bool isWon();       // Call to determine if the grid is in a winning state
	Item* playerPos(int, int);
	void setWon();
    	bool notWall(char ch);
    	bool isNeighbour(char sym, int r, int c);
	
	Character *createEnemy(int r, int c);
	Item *createItem(std::string, int r, int c);
	void attachCharToCell(Character* chr, int r, int c);
	void attachItemToCell(Item* item, int r, int c);
	void movePC(std::string dir, int r, int c); // moves player character only
	bool movePC(char dir, int r, int c);
	bool usePotion(std::string dir,int r, int c);
    	void attack(std::string dir, int r, int c);
	void moveEnemy(Character* enemy, int r, int c);
	void enemyReact();
	void storeEnemies();
	Cell* cellAt(int r, int c);
	void findChambers(std::string* grid);
	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif
