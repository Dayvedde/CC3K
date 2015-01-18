#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "character.h"
#include <string>

class Human: public Character{
	char symbol, onObj;
	int r, c;
	std::string race;
	static Human *instance;
	static void cleanup();
	double dmgA, health, gold, maxHP, attack, defence;
	Human();
    
public:
	static void setInstance();
	int getHealth();
	int getAttack();
	int getDefence();
	int getMaxHealth();
    
	void setHealth(int);
	void setAttack(int);
	void setDefence(int);
	void setGold(double);
	double getGold();
	int getDamage(Character *c);
	char getSymbol();
	std::string getRace();
	void setCoords(int r, int c);
	int getR();
	int getC();
	void move(std::string dir);
	static Human *getInstance();
	char getOnObj();
	void setOnObj(char obj);
    
	~Human();

};

#endif
