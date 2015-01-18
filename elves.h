#ifndef __ELVES_H__
#define __ELVES_H__

#include "character.h"
#include <string>

class Elves: public Character{
	char symbol, onObj;
	int r, c;
	double dmgA, health, attack, defence, gold, maxHP;
	std::string race;
	static Elves *instance;
	static void cleanup();
	Elves();
    
public:
	static void setInstance();	
	int getHealth();
	int getAttack();
	int getDefence();
	int getMaxHealth();
    
	int getNumPlayer();
	void setNumPlayer();
    
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
	char getOnObj();
	void setOnObj(char obj);
    
	static Elves *getInstance();
    
	~Elves();
    
};

#endif
