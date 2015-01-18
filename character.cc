#include "character.h"

#include <string>

using namespace std;

Character::Character(){}

Character::Character(Item* i): dh(i){}

int Character::numPlayer = 0;

bool Character::dead = false;

string Character::playerType = "";

int Character::getNumPlayer(){
    return numPlayer;
}

void Character::setNumPlayer(){
    numPlayer++;
}

bool Character::isDead(){
    return dead;
}

void Character::setDead(){
    dead = true;
}

void Character::setType(string s){
    playerType = s;
}

string Character::pchrType(){
    return playerType;
}

Item* Character::getItem(){
	return dh;
}

Character::~Character(){}
