#include "troll.h"
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;
// need to make singleton!
Troll::Troll(){
	symbol = 'T';
	health = 120;
	attack = 25;
	defence = 15;
	race = "troll";
	gold = 1;
	onObj = '.';
	dmgA = 100;
}

int Troll::getHealth(){ return health; }
int Troll::getAttack(){ return attack; }
int Troll::getDefence(){ return defence; }
int Troll::getDamage(Character *c){
	return ceil((dmgA / (dmgA + defence)) * c->getAttack());
}

string Troll::getRace() { return race; }
double Troll::getGold() { return gold; }
char Troll::getSymbol(){ return symbol; }

void Troll::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

int Troll::getMaxHealth(){ return maxHP; }
void Troll::setGold(double i){ gold = i; }
void Troll::setHealth(int i){
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
void Troll::setAttack(int i){ attack = i;}
void Troll::setDefence(int i){ defence = i;}
int Troll::getR(){ return r; }
int Troll::getC(){ return c; }
char Troll::getOnObj() { return onObj; }
void Troll::setOnObj(char obj){
	onObj = obj;
}

Troll::~Troll(){}
