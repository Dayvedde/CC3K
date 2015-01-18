#ifndef __CELL_H__
#define __CELL_H__

#include "character.h"
#include "item.h"


class Cell {
	int r, c;
	char object;
	Character *chr;
	Item *item;
	int chamberNum;
		
public:
	Cell();
	~Cell();
	void setCoords(int r, int c);
	void setObject(char obj);
	int getR();
	int getC();
	void setChr(Character* chr);
	Character* getChr();
	
	void setItem(Item *item);
	Item* getItem();

	void setChamberNum(int n);
	int getChamberNum();
};

#endif
