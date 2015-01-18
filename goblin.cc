#include "goblin.h"
#include <string>
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;
// need to make singleton!
Goblin::Goblin(){
	symbol = 'N';
	health = 70;
	maxHP = health;
	attack = 5;
	defence = 10;
	race = "goblin";
	gold = 1;
	onObj = '.';
	dmgA = 100;
}

int Goblin::getHealth(){ return health; }
int Goblin::getAttack(){ return attack; }
int Goblin::getDefence(){ return defence; }
int Goblin::getDamage(Character *c){
//	double dmgA = 100;
	return ceil((dmgA / (dmgA + defence)) * c->getAttack());
}
string Goblin::getRace() { return race; }
char Goblin::getSymbol(){ return symbol; }
double Goblin::getGold() { return gold; }
void Goblin::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

int Goblin::getMaxHealth(){ return maxHP; }
void Goblin::setGold(double i){ gold = i; }
void Goblin::setHealth(int i){
	if (i <= 0){
		health = 0;
	}
	else if (i > maxHP){
		health = maxHP;
	}
	else {
		health = i;
	}
}
void Goblin::setAttack(int i){ attack = i;}
void Goblin::setDefence(int i){ defence = i;}
int Goblin::getR(){ return r; }
int Goblin::getC(){ return c; }
char Goblin::getOnObj(){ return onObj; }
void Goblin::setOnObj(char obj){
	onObj = obj;
}
