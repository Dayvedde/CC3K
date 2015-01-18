#include "dragonhorde.h"
#include <string>

using namespace std;

DragonHorde::DragonHorde(): Item(6, 'G', false) {}

void DragonHorde::removeEffect(Character &c){}

void DragonHorde::getEffect(Character &c){
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

double DragonHorde::getVal(Character &c){
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

string DragonHorde::getType(){
	return "Dragon Horde";
}

char DragonHorde::getSymbol(){
	return symbol;
}

void DragonHorde::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

void DragonHorde::setLootable(bool l){
//	cout << "Setting lootable dragon" << endl;
	lootable = true;
}

bool DragonHorde::getLootable(){
	return lootable;
}

int DragonHorde::getR(){return r;}
int DragonHorde::getC(){return c;}
