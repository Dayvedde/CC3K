#include "superman.h"
#include <string>
#include <cstdlib>
#include <math.h>
#include <stdio.h>

using namespace std;

Superman *Superman::instance = 0;

Superman::Superman(){
	symbol = '@';
	health = 500;
	maxHP = health;
	attack = 50;
	defence = 100;
	race = "Superman";
	gold = 100;
	dmgA = 100;
	onObj = '.';
	lives = 2;
}

Superman *Superman::getInstance(){
	if (!instance){
		instance = new Superman;
		atexit(cleanup);
	}
	return instance;
}

void Superman::cleanup(){
	delete instance;
}

int Superman::getHealth(){ return health; }
int Superman::getAttack(){ return attack; }
int Superman::getDefence(){ return defence; }
int Superman::getMaxHealth(){ return maxHP; }
void Superman::setHealth(int num){
	if (num < 0){
		health = 0;
	}
	else if (num > maxHP){
		health = maxHP;
	}
	else {
		health = num;
	}
}
void Superman::setAttack(int num){ attack = num; }
void Superman::setDefence(int num){ defence = num; }
void Superman::setGold(double num){ gold = num; }
int Superman::getDamage(Character *c){
	return ceil((dmgA / (dmgA + defence)) * c->getAttack());
}
string Superman::getRace() { return race; }
char Superman::getSymbol(){ return symbol; }

void Superman::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

int Superman::getR() { return r; }
int Superman::getC() { return c; }
char Superman::getOnObj() { return onObj; }
void Superman:: setOnObj(char obj){ onObj = obj; }
double Superman::getGold() { return gold; }

void Superman::heal(){
	if ((health * 1.5) > maxHP){
		health = maxHP;
	}
	else {
		health = health * 1.5;
	}
}

Superman::~Superman(){}
