#ifndef __NORMAL_H__
#define __NORMAL_H__

#include <iostream>
#include <string>
#include "item.h"
#include "character.h"

class Normal: public Item{
	int r, c;
public:
	Normal();
	void getEffect(Character &c);
	void removeEffect(Character &c);
	std::string getType();
	double getVal(Character &c);
	char getSymbol();
	void setCoords(int r, int c);
	void setLootable(bool l);
	bool getLootable();
	int getR();
	int getC();
};

#endif
