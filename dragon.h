#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "character.h"
#include <string>
#include "item.h"
#include "dragonhorde.h"

class Dragon: public Character {
	char symbol, onObj;
	int r, c;
	double dmgA, health, attack, defence, gold, maxHP;
	std::string race;
//    	Item *dh; // point to the dragon hoard
public:
	Dragon(Item *dh);
	int getHealth();
	int getAttack();
	int getDefence();
	int getDamage(Character *c);
	char getSymbol();
	double getGold();
	std::string getRace();
	void setCoords(int r, int c);
	int getMaxHealth();
	void setGold(double);
	void setHealth(int);
	void setAttack(int);
	void setDefence(int);
	int getR();
	int getC();
	char getOnObj();
	void setOnObj(char obj);
};

#endif
