#include "vampire.h"
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;
// need to make singleton!
Vampire::Vampire(){
	symbol = 'V';
	health = 50;
	maxHP = health;
	attack = 25;
	defence = 25;
	race = "vampire";
	gold = 1;
	onObj = '.';
	dmgA = 100;
}

int Vampire::getHealth(){ return health; }
int Vampire::getAttack(){ return attack; }
int Vampire::getDefence(){ return defence; }
int Vampire::getDamage(Character *c){
	return ceil((dmgA / (dmgA + defence)) * c->getAttack());
}
string Vampire::getRace() { return race; }
char Vampire::getSymbol(){ return symbol; }

void Vampire::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}
double Vampire::getGold(){ return gold;}

int Vampire::getMaxHealth(){ return maxHP; }
void Vampire::setGold(double i){ gold = i; }
void Vampire::setHealth(int i){
	if (i < 0){
		health = 0;
	}
	else if (i > maxHP){
		health = maxHP;
	}
	else {
		health = i;
	}
}
void Vampire::setAttack(int i){ attack = i;}
void Vampire::setDefence(int i){ defence = i;}
int Vampire::getR(){ return r; }
int Vampire::getC(){ return c; }
char Vampire::getOnObj() { return onObj; }
void Vampire::setOnObj(char obj){
	onObj = obj;
}

Vampire::~Vampire(){}
