#include "orc.h"
#include <string>
#include <cstdlib>
#include <math.h>
#include <stdio.h>

using namespace std;

Orc *Orc::instance = 0;

void Orc::setInstance(){
    instance = 0;
}

// Default constructor
Orc::Orc(){
	symbol = '@';
	health = 180;
	maxHP = health;
	attack = 30;
	defence = 25;
	race = "orc";
	gold = 0;
	dmgA = 100;
	onObj = '.';
}

Orc *Orc::getInstance(){
	if (!instance && (Character::getNumPlayer() == 0)){
		instance = new Orc;
		Character::setNumPlayer();
		atexit(cleanup);
	}
	return instance;
}

void Orc::cleanup(){
	delete instance;
}

int Orc::getHealth(){ return health; }
int Orc::getAttack(){ return attack; }
int Orc::getDefence(){ return defence; }
int Orc::getMaxHealth(){ return maxHP; }
void Orc::setHealth(int num){
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
void Orc::setAttack(int num){ attack = num; }
void Orc::setDefence(int num){ defence = num; }
void Orc::setGold(double num) { gold = num; }
int Orc::getDamage(Character *c){
	return ceil((dmgA / (dmgA + defence)) * c->getAttack());
}
string Orc::getRace() { return race; }
char Orc::getSymbol(){ return symbol; }

void Orc::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

double Orc::getGold(){ return gold; }

int Orc::getR(){ return r; }
int Orc::getC(){ return c; }

char Orc::getOnObj(){ return onObj; }
void Orc::setOnObj(char obj){
    onObj = obj;
}

Orc::~Orc(){}
