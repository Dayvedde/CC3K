#ifndef __ITEM_H__
#define __ITEM_H__

#include <iostream>
#include <string>
#include "character.h"

class Character;

class Item{
protected:
	int value;
	char symbol;
	bool lootable;
public:
	Item(int num = 0, char sym = 0, bool loot = true);
	virtual void getEffect(Character &c)=0;
	virtual void removeEffect(Character &c) = 0;
	virtual std::string getType()=0;
	virtual char getSymbol()=0;
	virtual double getVal(Character &c) = 0;
	virtual void setCoords(int r, int c) = 0;
	virtual bool getLootable() = 0;
	virtual void setLootable(bool l) = 0;
	int randVal();
	virtual int getR() = 0;
	virtual int getC() = 0;
};

#endif
