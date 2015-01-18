#include "elves.h"
#include <string>
#include <cstdlib>
#include <math.h>
#include <stdio.h>

using namespace std;

Elves *Elves::instance = 0;

void Elves::setInstance(){
	instance = 0;
}

// Default constructor
Elves::Elves(){
	symbol = '@';
	health = 140;
	maxHP = health;
	attack = 30;
	defence = 10;
	race = "Elf";
	gold = 0;
	onObj = '.';
	dmgA = 100;
}


Elves *Elves::getInstance(){
	if (!instance && (Character::getNumPlayer() == 0)){
		instance = new Elves;
		Character::setNumPlayer();
		atexit(cleanup);
	}
	return instance;
}

void Elves::cleanup(){
	delete instance;
}

int Elves::getHealth(){	return health; }
int Elves::getAttack(){ return attack; }
int Elves::getDefence(){ return defence; }
int Elves::getMaxHealth(){ return maxHP; }
void Elves::setHealth(int num){
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
void Elves::setAttack(int num){ attack = num; }
void Elves::setDefence(int num){ defence = num; }
void Elves::setGold(double num) { gold = num; }
int Elves::getDamage(Character *c){
	return ceil((dmgA / (dmgA + defence)) * c->getAttack());
}
string Elves::getRace() { return race; }
char Elves::getSymbol(){ return symbol; }

void Elves::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

int Elves::getR(){ return r; }
int Elves::getC(){ return c; }
char Elves::getOnObj() { return onObj; }
void Elves::setOnObj(char obj){
	onObj = obj;
}

double Elves::getGold(){ return gold; }

Elves::~Elves(){}
