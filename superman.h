#ifndef __SUPERMAN_H__
#define __SUPERMAN_H__

#include "character.h"
#include <string>

class Superman: public Character{
	char symbol, onObj;
	int r, c, lives;
	std::string race;
	static Superman *instance;
	static void cleanup();
	double dmgA, health, gold, maxHP, attack, defence;
	Superman();

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
	void setCoords(int, int);
	int getR();
	int getC();
	void move(std::string);
	static Superman *getInstance();
	char getOnObj();
	void setOnObj(char obj);
	
	void heal();	

	~Superman();
};

#endif
