#include "dragon.h"
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;
Dragon::Dragon(Item* dh):Character(dh){
	symbol = 'D';
	health = 150;
	attack = 20;
	defence = 20;
	race = "Dragon";
	gold = 0;
	onObj = '.';
	dmgA = 100;
}

int Dragon::getHealth(){ return health; }
int Dragon::getAttack(){ return attack; }
int Dragon::getDefence(){ return defence; }
int Dragon::getDamage(Character *c){
	int damage = ceil((dmgA / (dmgA + defence)) * c->getAttack());
	return damage;
}
string Dragon::getRace() { return race; }
char   Dragon::getSymbol(){ return symbol; }
double    Dragon::getGold() { return gold; }
void   Dragon::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

int Dragon::getMaxHealth(){ return maxHP; }
void Dragon::setGold(double i){ gold = i; }
void Dragon::setHealth(int i){
	if (i <= 0){
		health = 0;
		dh->setLootable(true);
    }
	else if (i > 0) {
		health = i;
	}
}
void Dragon::setAttack(int i){ attack = i;}
void Dragon::setDefence(int i){ defence = i;}
int Dragon::getR(){ return r; }
int Dragon::getC(){ return c; }
char Dragon::getOnObj(){ return onObj; }
void Dragon::setOnObj(char obj){
	onObj = obj;
}
