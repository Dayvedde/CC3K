#include "textdisplay.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

TextDisplay::TextDisplay(string file){
	if (file == ""){
	
	theDisplay[0]  = "|-----------------------------------------------------------------------------|";
	theDisplay[1]  = "|                                                                             |";
	theDisplay[2]  = "| |--------------------------|        |-----------------------|               |";
	theDisplay[3]  = "| |..........................|        |.......................|               |";
	theDisplay[4]  = "| |..........................+########+.......................|-------|       |";
	theDisplay[5]  = "| |..........................|   #    |...............................|--|    |";
	theDisplay[6]  = "| |..........................|   #    |..................................|--| |";
	theDisplay[7]  = "| |----------+---------------|   #    |----+----------------|...............| |";
	theDisplay[8]  = "|            #                 #############                |...............| |";
	theDisplay[9]  = "|            #                 #     |-----+------|         |...............| |";
	theDisplay[10] = "|            #                 #     |............|         |...............| |";
	theDisplay[11] = "|            ###################     |............|   ######+...............| |";
	theDisplay[12] = "|            #                 #     |............|   #     |...............| |";
	theDisplay[13] = "|            #                 #     |-----+------|   #     |--------+------| |";
	theDisplay[14] = "|  |---------+-----------|     #           #          #              #        |";
	theDisplay[15] = "|  |.....................|     #           #          #         |----+------| |";
	theDisplay[16] = "|  |.....................|     ########################         |...........| |";
	theDisplay[17] = "|  |.....................|     #           #                    |...........| |";
	theDisplay[18] = "|  |.....................|     #    |------+--------------------|...........| |";
	theDisplay[19] = "|  |.....................|     #    |.......................................| |";
	theDisplay[20] = "|  |.....................+##########+.......................................| |";
	theDisplay[21] = "|  |.....................|          |.......................................| |";
	theDisplay[22] = "|  |---------------------|          |---------------------------------------| |";
	theDisplay[23] = "|                                                                             |";
	theDisplay[24] = "|-----------------------------------------------------------------------------|";
	}
    
	else {
		ifstream infile (file.c_str());
		for (int i = 0; i < 25; i++){
			getline(infile, theDisplay[i]);
		}
	}
}

ostream &operator<<(ostream &out, const TextDisplay &td){
	char c;
	#ifndef BONUS
	if (td.theDisplay){
		for (int i = 0; i < 25; i++){
			for (int j = 0; j < 79; j++){
				c = td.theDisplay[i][j];
				out << td.theDisplay[i][j];
			}
			cout << endl;
		}
	}
	#endif

	#ifdef BONUS
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, 0);
	init_pair(5, COLOR_MAGENTA, 0);
	init_pair(6, COLOR_CYAN, 0);
	init_pair(7, COLOR_WHITE, 0);
	move(0,0);
	if (td.theDisplay){
		for (int i = 0; i < 25; i++){
			for (int j = 0; j < 79; j++){
				c = td.theDisplay[i][j];
				if (c == 'P') {
					 attron(COLOR_PAIR(1));
 				}
 				else if (c == '@'){
					attron(COLOR_PAIR(6));
				}
				else if (c == 'N'||c=='V'||c=='W'||c=='X'||c=='T'||c=='M'){
					attron(COLOR_PAIR(3));
				}
				else if (c=='.'){
					attron(COLOR_PAIR(2));
				}
				else if (c == '#'|| c=='-'||c=='|'||c=='+'){
					attron(COLOR_PAIR(5));
				}
				else if (c == 'G'){
					attron(COLOR_PAIR(4));
				}
				else if (c == 'D'){
					attron(COLOR_PAIR(7));
				}
				printw("%c", c);
				attron(COLOR_PAIR(7));
			}
			printw("\n");
		}
	}
	refresh();
	#endif
	return out;
}

// function to check if a cell is occupied, may not need
bool TextDisplay::isOccupied(int r, int c){
	return theDisplay[r][c] != '.';	
}

// returns the character at row [r] and column [c]
char TextDisplay::getCell(int r, int c){
	return theDisplay[r][c];
}

void TextDisplay::setCell(char symbol, int r, int c){
	theDisplay[r][c] = symbol;
}

char TextDisplay::getCell(string dir, int r, int c){
	if (dir == "no"){
		r--;
	}
	else if (dir == "ea"){
		c++;
	}
	else if (dir == "so"){
		r++;
	}
	else if (dir == "we"){
		c--;
	}	
	else if (dir == "nw"){
		r--;
		c--;
	}	
	else if (dir == "ne"){
		r--;
		c++;
	}
	else if (dir == "se"){
		r++;
		c++;
	}
	else if (dir == "sw"){
		r++;
		c--;
	}
	else {
		cout << "Invalid" << endl;
		return 0;
	}
	return theDisplay[r][c];
}

string* TextDisplay::getTheDisplay(){
	return theDisplay;
}
