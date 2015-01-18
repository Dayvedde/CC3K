#ifndef __DRAGONHORDE_H__
#define __DRAGONHORDE_H__

#include <iostream>
#include <string>
#include "item.h"
#include "character.h"
#include "dragon.h"

class DragonHorde: public Item{
	int r, c;	
	bool lootable;
public:
	DragonHorde();
	void getEffect(Character &c);
	void removeEffect(Character &c);
	double getVal(Character &c);
	std::string getType();
	char getSymbol();
	void setCoords(int r, int c);
	void setLootable(bool l);
	bool getLootable();
	int getR();
	int getC();
};

#endif
