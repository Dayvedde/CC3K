#include "human.h"
#include <string>
#include <cstdlib>
#include <math.h>
#include <stdio.h>

using namespace std;

Human *Human::instance = 0;

// Default constructor
Human::Human(){
	symbol = '@';
	health = 140000;
	maxHP = health;
	attack = 20;
	defence = 20;
	race = "human";
	gold = 0;
	dmgA = 100;
	onObj = '.';
}

// return an instance of Human, singleton design
Human *Human::getInstance(){
	if (!instance){
		instance = new Human;
		atexit(cleanup);
	}
	return instance;
}

void Human::cleanup(){
	delete instance;
}

// gets attributes of human

int Human::getHealth(){	return health; }
int Human::getAttack(){ return attack; }
int Human::getDefence(){ return defence; }
int Human::getMaxHealth(){ return maxHP; }
int Human::getDamage(Character *c){
	return ceil((dmgA / (dmgA + defence)) * c->getAttack());
}
string Human::getRace() { return race; }
char Human::getSymbol() { return symbol; }
int Human::getR(){ return r; }
int Human::getC(){ return c; }
char Human::getOnObj() { return onObj; }
double Human::getGold(){ return gold; }

// sets attributes of human

void Human::setHealth(int num){
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
void Human::setAttack(int num){ attack = num; }
void Human::setDefence(int num){ defence = num; }
void Human::setGold(double num) { gold = num; }
void Human::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

void Human::setOnObj(char obj){
	onObj = obj;
}

Human::~Human(){}
