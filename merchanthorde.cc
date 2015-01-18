#include "merchanthorde.h"
#include <string>

using namespace std;

MerchantHorde::MerchantHorde(): Item(4, 'G',true){}

void MerchantHorde::removeEffect(Character &c){}

void MerchantHorde::getEffect(Character &c){
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

double MerchantHorde::getVal(Character &c){
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

string MerchantHorde::getType(){
	return "Merchant Horde";
}

char MerchantHorde::getSymbol(){
	return symbol;
}

void MerchantHorde::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

void MerchantHorde::setLootable(bool l){
	lootable = l;
}

bool MerchantHorde::getLootable(){
	return lootable;
}

int MerchantHorde::getR(){ return r;}
int MerchantHorde::getC(){ return c;}
