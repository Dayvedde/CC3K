#include "boostatk.h"
#include <string>

using namespace std;

bool BoostAtk::encountered = false;

BoostAtk::BoostAtk(): Item(5, 'P', true){}

BoostAtk::~BoostAtk(){}

void BoostAtk::removeEffect(Character &c){
	int newAttack = c.getAttack() - value;
	c.setAttack (newAttack);	
}

double BoostAtk::getVal(Character &c){}

bool BoostAtk::isEncountered(){
	return encountered;
}

void BoostAtk::setEncounter(bool b){
	encountered = b;
}

void BoostAtk::getEffect(Character &c){
	int n = c.getAttack() + value;
	c.setAttack(n);
}

string BoostAtk::getType(){
	return "Boost Attack";
}

char BoostAtk::getSymbol(){
	return symbol;
}

void BoostAtk::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

void BoostAtk::setLootable(bool l){
	lootable = l;
}

bool BoostAtk::getLootable(){
	return lootable;
}

int BoostAtk::getR(){ return r; }
int BoostAtk::getC(){ return c; }
