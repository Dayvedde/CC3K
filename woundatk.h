#ifndef __WOUNDATK_H__
#define __WOUNDATK_H__

#include <iostream>
#include "item.h"
#include "character.h"

class WoundAtk: public Item {
	static bool encountered;
	int r, c;
public:
	WoundAtk();
	static bool isEncountered();
	static void setEncounter(bool);
	void getEffect(Character &c);
	void removeEffect(Character &c);
	double getVal(Character &c);
	std::string getType();
	char getSymbol();
	void setCoords(int r, int c);
	bool getLootable();	
	void setLootable(bool l);
	int getR();
	int getC();
};

#endif
