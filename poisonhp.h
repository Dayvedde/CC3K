#ifndef __POISONHP_H__
#define __POISONHP_H__

#include <iostream>
#include "item.h"
#include "character.h"

class PoisonHP: public Item {
	static bool encountered;
	int r, c;
public:
	PoisonHP();
	static bool isEncountered();
	static void setEncounter(bool);
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
