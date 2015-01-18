#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <sstream>
#include <string>
#include "character.h"
#include <ncurses.h>

class TextDisplay {
	std::string theDisplay[30];
    
public:
	TextDisplay(std::string file = "");
	bool isOccupied(int r, int c);
	char getCell(int r, int c);
	char getCell (std::string dir, int r, int c);
	void setCell(char symbol, int r, int c);
	std::string* getTheDisplay();
	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
