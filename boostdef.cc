#include "boostdef.h"
#include <string>

using namespace std;

bool BoostDef::encountered = false;

BoostDef::BoostDef(): Item(5, 'P'){}

BoostDef::~BoostDef(){}

void BoostDef::removeEffect(Character &c){
	int newDef = c.getDefence() - value;
	c.setDefence(newDef);
}

double BoostDef::getVal(Character &c){}

bool BoostDef::isEncountered(){
	return encountered;
}

void BoostDef::setEncounter(bool b){
	encountered = b;
}

void BoostDef::getEffect(Character &c){
	int n = c.getDefence() + value;
	c.setDefence(n);
}

string BoostDef::getType(){
	return "Boost Defence";
}

char BoostDef::getSymbol(){
	return symbol;
}

void BoostDef::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

void BoostDef::setLootable(bool l){
	lootable = l;
}

bool BoostDef::getLootable(){
	return lootable;
}

int BoostDef::getR(){return r;}
int BoostDef::getC(){return c;}
