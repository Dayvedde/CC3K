#include "normal.h"
#include <string>

using namespace std;

Normal::Normal(): Item(1, 'G', true){}

void Normal::removeEffect(Character& c){}

void Normal::getEffect(Character &c){
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

double Normal::getVal(Character &c){
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

string Normal::getType(){
	return "Normal";
}

char Normal::getSymbol(){
	return 'G';
}

void Normal::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

void Normal::setLootable(bool b){
	lootable = b;
}	

bool Normal::getLootable(){
	return lootable;
}
	
int Normal::getR(){return r;}
int Normal::getC(){return c;}
