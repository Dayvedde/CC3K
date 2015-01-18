#include "poisonhp.h"
#include <string>

using namespace std;

bool PoisonHP::encountered = false;

PoisonHP::PoisonHP(): Item(randVal(), 'P'){}

bool PoisonHP::isEncountered(){
	return encountered;
}

void PoisonHP::setEncounter(bool b){
	encountered = b;
}

void PoisonHP::removeEffect(Character &c){}

double PoisonHP::getVal(Character &c){}

void PoisonHP::getEffect(Character &c){
	int n = c.getHealth();
	string chr = c.getRace();
	if (chr == "Elf"){
		if ((n+value)>=0){
			n = c.getMaxHealth();
		}
		else {
			n += value;
		}
	}
	else if ((n - value) >= 0){
		n -= value;
	}
	else {
		n = 0;
	}
	c.setHealth(n);
}

string PoisonHP::getType(){
	return "Poison Health";
}

char PoisonHP::getSymbol(){
	return symbol;
}

void PoisonHP::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

void PoisonHP::setLootable(bool l){
	lootable = l;
}

bool PoisonHP::getLootable(){
	return lootable;
}

int PoisonHP::getR(){return r;}
int PoisonHP::getC(){return c;}
