#include "wounddef.h"
#include <string>

using namespace std;

bool WoundDef::encountered = false;

WoundDef::WoundDef(): Item(5, 'P', true){}

bool WoundDef::isEncountered(){
	return encountered;
}

void WoundDef::setEncounter(bool b){
	encountered = b;
}

double WoundDef::getVal(Character &c){}

void WoundDef::removeEffect(Character &c){
	int newDef;
	string chr = c.getRace();
	if (chr == "Elf"){
		newDef = c.getDefence() - value;
	}
	else {
		newDef = c.getDefence() + value;
	}
	c.setDefence(newDef);
}

void WoundDef::getEffect(Character &c){
	int n = c.getDefence();
	string chr = c.getRace();
	if (chr == "Elf"){
		n+=value;
	}
	else if ((n - value) >= 0){
		n -= value;
	}
	else {
		n = 0;
	}
	c.setDefence(n);
}

string WoundDef::getType(){
	return "Wound Defence";
}

char WoundDef::getSymbol(){
	return symbol;
}

void WoundDef::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

bool WoundDef::getLootable(){
	return lootable;
}

void WoundDef::setLootable(bool b){
	lootable = b;
}

int WoundDef::getR(){return r;}
int WoundDef::getC(){return c;}
