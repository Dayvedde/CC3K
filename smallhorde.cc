#include "smallhorde.h"
#include <string>

using namespace std;

SmallHorde::SmallHorde(): Item(2, 'G', true){}

void SmallHorde::removeEffect(Character &c){}

void SmallHorde::getEffect(Character &c){
	double goldVal = 0;
	if (c.getRace() == "dwarf"){
		goldVal = c.getGold() + (2 * value);
	}
	else if (c.getRace() == "orc"){
		goldVal = c.getGold() + (value / 2);
	}
	else{
		goldVal = c.getGold() + value;
	} 
	c.setGold(goldVal);
}

double SmallHorde::getVal(Character &c){
	double goldVal = 0;
	if (c.getRace() == "dwarf"){
		goldVal = 2 * value;
	}
	else if (c.getRace() == "orc"){
		goldVal = value / 2;
	}
	else{
		goldVal = value;
	}
	return goldVal;
}

string SmallHorde::getType(){
	return "Small Horde";
}

char SmallHorde::getSymbol(){
	return symbol;
}

void SmallHorde::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

void SmallHorde::setLootable(bool l){
	lootable = l;
}

bool SmallHorde::getLootable(){
	return lootable;
}

int SmallHorde:: getR(){return r;}
int SmallHorde::getC(){return c;}
