#ifndef __MERCHANTHORDE_H__
#define __MERCHANTHORDE_H__

#include <iostream>
#include <string>
#include "item.h"
#include "character.h"

class MerchantHorde: public Item{
	int r, c;
public:
	MerchantHorde();
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
