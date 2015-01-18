#include "woundatk.h"
#include <string>

using namespace std;

bool WoundAtk::encountered = false;

WoundAtk::WoundAtk(): Item(5, 'P',true) {}

bool WoundAtk::isEncountered(){
	return encountered;
}

void WoundAtk::setEncounter(bool b){
	encountered = b;
}

double WoundAtk::getVal(Character &c){}

void WoundAtk::removeEffect(Character &c){
	int newAtk;
	string chr = c.getRace();
	if (chr == "Elf"){
		newAtk = c.getAttack() - value;
	}
	else {
		newAtk = c.getAttack() + value;
	}
	c.setAttack(newAtk);
}

void WoundAtk::getEffect(Character &c){
	int n = c.getAttack();
	string chr = c.getRace();
	if (chr == "Elf"){
		n += value;
	}
	else if ((n - value) >= 0){
		n -= value;
	}
	else {
		n = 0;
	}
	c.setAttack(n);
}

string WoundAtk::getType(){
	return "Wound Attack";
}

char WoundAtk::getSymbol(){
	return symbol;
}

void WoundAtk::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

bool WoundAtk::getLootable(){
	return lootable;
}

void WoundAtk::setLootable(bool l){
	lootable = l;
}

int WoundAtk::getR(){return r;}
int WoundAtk::getC(){return c;}
