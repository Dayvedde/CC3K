#include "phoenix.h"
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;
// need to make singleton!
Phoenix::Phoenix(){
	symbol = 'X';
	health = 50;
	maxHP = health;
	attack = 35;
	defence = 20;
	race = "phoenix";
	gold = 1;
	onObj = '.';
	dmgA = 100;
}

int Phoenix::getHealth(){ return health; }
int Phoenix::getAttack(){ return attack; }
int Phoenix::getDefence(){ return defence; }
int Phoenix::getDamage(Character *c){
	return ceil((dmgA / (dmgA + defence)) * c->getAttack());
}

string Phoenix::getRace() { return race; }
char Phoenix::getSymbol(){ return symbol; }
double Phoenix::getGold() { return gold;}
void Phoenix::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

int Phoenix::getMaxHealth(){ return maxHP; }
void Phoenix::setGold(double i){ gold = i; }
void Phoenix::setHealth(int i){
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
void Phoenix::setAttack(int i){ attack = i;}
void Phoenix::setDefence(int i){ defence = i;}
int Phoenix::getR(){ return r; }
int Phoenix::getC(){ return c; }
char Phoenix::getOnObj() { return onObj; }
void Phoenix::setOnObj(char obj){
	onObj = obj;
}
Phoenix::~Phoenix(){}
