#include "merchant.h"
#include <string>
#include <math.h>
#include <stdio.h>
#include "merchanthorde.h"

using namespace std;

bool Merchant::angry = false;

// need to make singleton!
Merchant::Merchant(){
	symbol = 'M';
	health = 30;
	maxHP = health;
	attack = 70;
	defence = 5;
	race = "merchant";
	gold = 4;
	onObj = '.';
	dmgA = 100;
}

void Merchant::setAngry(){
	angry = true;
}

bool Merchant::getAngry(){
	return angry;
}

int Merchant::getHealth(){ return health; }
int Merchant::getAttack(){ return attack; }
int Merchant::getDefence(){ return defence; }
int Merchant::getDamage(Character *c){
	return ceil((dmgA / (dmgA + defence)) * c->getAttack());
}

string Merchant::getRace() { return race; }
char Merchant::getSymbol(){ return symbol; }
double Merchant::getGold() { return gold; }
void Merchant::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

int Merchant::getMaxHealth(){ return maxHP; }
void Merchant::setGold(double i){ gold = i; }
void Merchant::setHealth(int i){
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
void Merchant::setAttack(int i){ attack = i;}
void Merchant::setDefence(int i){ defence = i;}
int Merchant::getR(){ return r; }
int Merchant::getC(){ return c; }
char Merchant::getOnObj() { return onObj; }
void Merchant::setOnObj(char obj){
	onObj = obj;
}

Merchant::~Merchant(){}
