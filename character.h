#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <string>
#include "item.h"

class Item;

class Character {
	// coords?
	static int numPlayer;
	static bool dead;
	static std::string playerType;

public:
	Item *dh;
	Character();    
	static int getNumPlayer();
	static void setNumPlayer();
	static bool isDead();
	static void setDead();
	static std::string pchrType();
	static void setType(std::string);
	Character (Item* i);
	virtual int getHealth() = 0;
	virtual int getAttack() = 0;
	virtual int getDefence() = 0;
	virtual int getDamage(Character *c) = 0;
	virtual double getGold() = 0;
	virtual int getMaxHealth() = 0;
	virtual void setGold(double) = 0;
	virtual std::string getRace() = 0;
	virtual char getSymbol() = 0;
	virtual void setCoords(int r, int c) = 0;
	virtual void setHealth(int) = 0;
	virtual void setAttack(int) = 0;
	virtual void setDefence(int) = 0;
	virtual int getR() = 0;
	virtual int getC() = 0;
	virtual char getOnObj() = 0;
	virtual void setOnObj(char obj) = 0;
	Item* getItem();
	virtual ~Character();
};

#endif
