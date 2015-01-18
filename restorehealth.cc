#include "restorehealth.h"
#include <string>

using namespace std;

bool RestoreHealth::encountered = false;

RestoreHealth::RestoreHealth(): Item(randVal(), 'P',true){}

bool RestoreHealth::isEncountered(){
	return encountered;
}

void RestoreHealth::setEncounter(bool b){
	encountered = b;
}

void RestoreHealth::removeEffect(Character &c){}

double RestoreHealth::getVal(Character &c){}

void RestoreHealth::getEffect(Character &c){
	int maxHP = c.getMaxHealth();
	int n = c.getHealth();
	if ((n + value) <= maxHP){
		n += value;
	}
	else {
		n = maxHP;
	}
	c.setHealth(n);
}

string RestoreHealth::getType(){
	return "Restore Health";
}

char RestoreHealth::getSymbol(){
	return symbol;
}

void RestoreHealth::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

void RestoreHealth::setLootable(bool l){
	lootable = l;
}

bool RestoreHealth::getLootable(){
	return lootable;
}

int RestoreHealth::getR(){return r;}
int RestoreHealth::getC(){return c;}
