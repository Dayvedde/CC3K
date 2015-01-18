#include "cell.h"

using namespace std;

Cell::Cell(){
	r = -1;
	c = -1;
	chr = NULL;
	item = NULL;
}

Cell::~Cell(){
	if (chr&&chr->getSymbol()!= '@'){
		delete chr;
	}
	delete item;
}

void Cell::setCoords(int r, int c){
	this->r = r;
	this->c = c;
}

void Cell::setObject(char obj){
	object = obj;
}

int Cell::getR(){
	return r;
}
	
int Cell::getC(){
	return c;
}

void Cell::setChr(Character* chr){
	this->chr = chr;
}

Character* Cell::getChr(){
	return chr;
}

void Cell::setItem(Item* item){
	this->item = item;
}

Item* Cell::getItem(){
	return item;
}

void Cell::setChamberNum(int n){
	chamberNum = n;
}

int Cell::getChamberNum(){
	return chamberNum;
}

