#ifndef __SMALLHORDE_H__
#define __SMALLHORDE_H__

#include <iostream>
#include <string>
#include "item.h"
#include "character.h"

class SmallHorde: public Item{
	int r, c;
public:
	SmallHorde();
	void removeEffect (Character &c);
	void getEffect(Character &c);
	std::string getType();
	double getVal(Character &c);
	char getSymbol();
	void setCoords(int r, int c);
	int getR();
	int getC();
	void setLootable(bool l);
	bool getLootable();
};

#endif
