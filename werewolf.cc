#include "werewolf.h"
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;
Werewolf::Werewolf(){
	symbol = 'W';
	health = 120;
	maxHP = health;
	attack = 30;
	defence = 5;
	race = "werewolf";
	gold = 1;
	onObj = '.';
	dmgA = 100;
}

int Werewolf::getHealth(){ return health; }
int Werewolf::getAttack(){ return attack; }
int Werewolf::getDefence(){ return defence; }
int Werewolf::getDamage(Character *c){
	return ceil((dmgA / (dmgA + defence)) * c->getAttack());
}
string Werewolf::getRace() { return race; }
char Werewolf::getSymbol(){ return symbol; }

void Werewolf::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

double Werewolf::getGold(){ return gold;}

int Werewolf::getMaxHealth(){ return maxHP; }
void Werewolf::setGold(double i){ gold = i; }
void Werewolf::setHealth(int i){
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
void Werewolf::setAttack(int i){ attack = i;}
void Werewolf::setDefence(int i){ defence = i;}
int Werewolf::getR(){ return r; }
int Werewolf::getC(){ return c; }
char Werewolf::getOnObj() { return onObj; }
void Werewolf::setOnObj(char obj){
	onObj = obj;
}

Werewolf::~Werewolf(){}
