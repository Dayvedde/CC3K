#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

#include "textdisplay.h"
#include "character.h"
#include "floor.h"
#include "human.h"
#include "cell.h"
#include "dwarf.h"
#include "orc.h"
#include "elves.h"
#include "superman.h"

int main(int argv, char * argc[]){
    
	#ifndef BONUS
	string userIn = "";
	#endif
	#ifdef BONUS
	char userIn = 0;
	#endif

	int xCoordPC, yCoordPC;
	bool valid = false;
	char object;
   bool gameOver = false;
	Character *PC;
	string sPassword = "superman";
	int health;
	
   while (!gameOver && !Floor::gameWon()){			
	#ifdef BONUS
		initscr();
		curs_set(0);
		start_color();
		printw ("Choose a race: (h)uman, (e)lf , (d)ward , (o)rc, (s)uperman\n");
		userIn = getch();
		refresh();
	#endif
		
	#ifndef BONUS	    
   	cout << "Choose a race: (h)uman (e)lf (d)warf (o)rc" << endl;
	#endif

	while (!valid){
		#ifndef BONUS	
			cin >> userIn;
  			if (cin.eof()){
				gameOver = true;
         	break;
         }	
         if (userIn == "h"){
				cout << "You are now a Human" << endl;
				PC = Human::getInstance();
				valid = true;
			}           
			else if (userIn == "e"){
				cout << "You are now a magical Elf" << endl;
				PC = Elves::getInstance();
				valid = true;
			}
			else if (userIn == "d"){
			cout << "You are now a giant Dwarf" << endl;
			PC = Dwarf::getInstance();
			valid = true;
			}
			else if (userIn == "o"){
				cout << "You are now a super Orc" << endl;
				PC = Orc::getInstance();
				valid = true;
			}
		#endif

		#ifdef BONUS
		if (userIn == 'h'){
	  		printw("You are now a Human\n");
	      PC = Human::getInstance();
	      valid = true;
	   }
	   else if (userIn == 'e'){
	    	printw("You are now a magical Elf\n");
	   	PC = Elves::getInstance();
		   valid = true;
	   }
		else if (userIn == 'd'){
			printw("You are now a giant Dwarf\n");
			PC = Dwarf::getInstance();
			valid = true;
		}
		else if (userIn == 'o'){
			printw("You are now a super Orc\n");
			PC = Orc::getInstance();
			valid = true;
		}
		else if (userIn == 's'){
			printw("You are now Superman\n");
			PC = Superman::getInstance();
			valid = true;
		}
		#endif
		else {
		#ifndef BONUS
			cout << "The race: " << userIn << " have been wiped out, try again" << endl;
		#endif
		#ifdef BONUS
			printw("The race has been wiped out, try again\n");
		#endif
		}
	}
        
	if (gameOver){
		break;
	}
    	
	#ifdef BONUS
		stringstream ss;
		string userIn2;
		ss << userIn;
		ss >> userIn2;
	#endif
	#ifndef BONUS
		string userIn2 = userIn;
	#endif
        Floor f(userIn2);
        if (argv == 1){
            f.init("");
            cout << f;
        }
        else if (argv == 2){
            string file = argc[1];
            f.init(file);
            cout << f;
      }
        
	  #ifndef BONUS
     cout << "Welcome to CC3K!" << endl;
      
		while (cin >> userIn){
		xCoordPC = PC->getR();
		yCoordPC = PC->getC();
		if (userIn=="no"||userIn=="so"||userIn=="ea"||userIn=="we"
			||userIn=="ne"||userIn=="nw"||userIn=="se"||userIn=="sw"){
			f.movePC(userIn, xCoordPC, yCoordPC);
			valid = true;
		}
		else if (userIn[0] == 'u'){
			if (f.usePotion(userIn.substr(1), xCoordPC, yCoordPC)){
				valid = true;
			}
		} 
		else if (userIn[0] == 'a'){
			f.attack(userIn.substr(1), xCoordPC, yCoordPC);
			valid = true;
		}
		else if (userIn == "r"){
			f.resetFloor();
			valid = false;
			break;
		}
		else if (userIn == "q"){
			gameOver = true;
			break;
		}
	else {
		cout << "INVALID COMMAND. TRY AGAIN." << endl;
		valid = false;
	}
	if (valid){
		if (!Character::isDead() && !Floor::gameWon()){
		cout << "Enemies reacting" << endl;
		f.enemyReact();
	}
	cout << f;
	f.printStats();
		if (Character::isDead() || Floor::gameWon()){
			return 0;
		}
	}
	cout << "Command: ";
}
#endif

	#ifdef BONUS
	while (userIn != 'k'){
		userIn = getch();
		xCoordPC = PC->getR();
		yCoordPC = PC->getC();
		if (userIn == 'w' || userIn == 's' || userIn == 'd' || userIn == 'a' || userIn == 'q' || userIn == 'e' || userIn == 'z' || userIn == 'c'|| userIn == 'h'){
			valid = f.movePC(userIn, xCoordPC, yCoordPC);
		}
		else if (userIn == 'r'){
			f.resetFloor();
			valid = false;
			erase();
			break;
		}
		if (valid) {
			if (!Character::isDead() && !Floor::gameWon()){
				f.enemyReact();
				cout << f;
				f.printStats();
			}
		}
		if (Character::isDead() || Floor::gameWon()){
			break;
		}
		valid = false;
		refresh();
	}
	if (Character::isDead()){
		erase();
		f.printStats();
		break;
	}
	else if (Floor::gameWon()){
		erase();
		f.printStats();
		break;
	}
	else if (userIn == 'k'){
		break;
	}
	refresh();
#endif
}

#ifdef BONUS
	if (userIn != 'k'){
		getch();
	}
	endwin();
	#endif
    //	 delete PC;    
    return 0;
}
