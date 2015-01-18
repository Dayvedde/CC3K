#include "dwarf.h"
#include <string>
#include <cstdlib>
#include <math.h>
#include <stdio.h>

using namespace std;

// sets Dwarf static instance

Dwarf *Dwarf::instance = 0;

// Default constructor
Dwarf::Dwarf(){
	symbol = '@';
	health = 100;
	maxHP = health;
	attack = 20;
	defence = 30;
	race = "dwarf";
	gold = 0;
	onObj = '.';
	dmgA = 100;
}

// Dwarf singleton functions 

Dwarf *Dwarf::getInstance(){
	if (!instance && (Character::getNumPlayer() == 0)){
		instance = new Dwarf;
        Character::setNumPlayer();
		atexit(cleanup);
	}
	return instance;
}

void Dwarf::cleanup(){
	delete instance;
}

// gets Dwarf attributes

int Dwarf::getHealth(){	return health; }
int Dwarf::getAttack(){ return attack; }
int Dwarf::getDefence(){ return defence; }
int Dwarf::getMaxHealth(){ return maxHP; }
int Dwarf::getDamage(Character *c){
	return ceil((dmgA / (dmgA + defence)) * c->getAttack());
}
string Dwarf::getRace() { return race; }
char Dwarf::getSymbol(){ return symbol; }
int Dwarf::getR(){ return r; }
int Dwarf::getC(){ return c; }
char Dwarf::getOnObj() { return onObj; }
double Dwarf::getGold(){ return gold; }

// sets Dwarf attributes

void Dwarf::setHealth(int num){
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
void Dwarf::setAttack(int num){ attack = num; }
void Dwarf::setDefence(int num){ defence = num; }
void Dwarf::setGold(double num) { gold = num; }
void Dwarf::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}
void Dwarf::setOnObj(char obj){
	onObj = obj;
}

Dwarf::~Dwarf(){}
