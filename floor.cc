#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "cell.h"
#include "floor.h"
#include <iomanip>
#include <cstring>
#include "superman.h"

using namespace std;

int TRACE = 1;

bool Floor::gameEnd = false;

bool Floor::gameWon(){
    return gameEnd;
}

void Floor::setGameWon(){
    gameEnd = true;
}

Floor::Floor(string race){
	won = false;
	floorLevel = 0;
   if (race == "h"){
      PChr = Human::getInstance();
   }
   else if (race == "o"){
      PChr = Orc::getInstance();
   }
   else if ( race == "e"){
      PChr = Elves::getInstance();
   }
   else if (race == "d"){
      PChr = Dwarf::getInstance();
   }
	else if (race == "s"){
		PChr = Superman::getInstance();
	}
}

Floor::~Floor(){
	clearFloor();
}

Item* Floor::playerPos(int r, int c){
	 Item* item1;
    if (td->getCell(r-1,c-1) == 'G' && cellAt(r-1, c-1)->getItem()->getType() == "Dragon Horde"){
	item1 = cellAt(r-1, c-1)->getItem();
    }
    else if (td->getCell(r-1,c) == 'G' && cellAt(r-1, c)->getItem()->getType() == "Dragon Horde"){
	item1 = cellAt(r-1, c)->getItem();
    }
    else if (td->getCell(r-1,c+1) == 'G' && cellAt(r-1, c+1)->getItem()->getType() == "Dragon Horde"){
			item1 = cellAt(r-1, c+1)->getItem();
    }
    else if (td->getCell(r, c-1) == 'G' && cellAt(r, c-1)->getItem()->getType() == "Dragon Horde"){
			item1 = cellAt(r, c-1)->getItem();
    }
    else if (td->getCell(r-1, c+1) == 'G' && cellAt(r-1, c+1)->getItem()->getType() == "Dragon Horde"){
			item1 = cellAt(r-1, c+1)->getItem();
    }
    else if (td->getCell(r+1, c-1) == 'G' && cellAt(r+1, c-1)->getItem()->getType() == "Dragon Horde"){
			item1 = cellAt(r-1, c+1)->getItem();
    }
    else if (td->getCell(r+1, c) == 'G' && cellAt(r+1, c)->getItem()->getType() == "Dragon Horde"){
	   item1 = cellAt(r+1, c)->getItem();
    }
    else if (td->getCell(r+1, c+1) == 'G' && cellAt(r+1, c+1)->getItem()->getType() == "Dragon Horde"){
			item1 = cellAt(r+1, c+1)->getItem();
    }
    return item1;
}

void Floor::clearFloor(){
	delete td;
	for (int i = 0; i < cells.size(); i++){
		delete cells[i];
	}
	for (int i = 0; i < potions.size(); i++){
		potions[i]->removeEffect(*PChr);
		delete potions[i];
	}
	cells.clear();
	potions.clear();
}

void Floor::resetFloor(){
	floorLevel = 0;
	RestoreHealth::setEncounter(false);
	BoostAtk::setEncounter(false);
	BoostDef::setEncounter(false);
	PoisonHP::setEncounter(false);
	WoundAtk::setEncounter(false);
	WoundDef::setEncounter(false); 
}


void Floor::init(string filename){
 	floorLevel++;
	if (floorLevel > 1){
		clearFloor();
	}
    
	int r = 0;
	int c = 0;
	int tempR = 0;
	int tempC = 0;
	int enemyLeft = 20;
	int potLeft = 10;
	int goldLeft = 10;
	int pcChamber;
	int randCham;
	char stairs = 92;
	bool loop = true;
	char tracker = 0;
	char cellSym;
	srand(time(0)); // make it random random
    
	won = false;
	td = new TextDisplay(filename);
	for (int i = 0; i < 25; i ++){
		for (int j = 0; j < 79; j ++){
			cellSym = td->getCell(i,j);
			if (notWall(cellSym) || cellSym == '+'|| cellSym == '#') {
				Cell *c = new Cell;
				c->setCoords(i,j);
				c->setObject(td->getCell(i,j));
				if (cellSym == '+'){
				c->setChamberNum(10);
				}
				else if (cellSym == '#'){
				c->setChamberNum(11);
				}
				cells.push_back(c);
			}
		}
	}
	// Finds all chambers and changes the cells accordingly
	
	if (filename == ""){
		findChambers(td->getTheDisplay());
	}
	//generate player
    	if (filename == ""){
        	while(td->isOccupied(r, c)){
            		r = rand()%25+1; // random from 1-25
            		c = rand()%79+1; // random from 1-79
        	}
    	}
    	else {
        	for (int i = 0; (i < 25) && loop; i++){
            		for (int j = 0; (j < 79) && loop; j ++){
                		if (td->getCell(i,j) == '@'){
                    		r = i;
                    		c = j;
                    		loop = false;
                		}
            		}
        	}
    	}
   	attachCharToCell(PChr, r, c);
		PChr->setCoords(r,c); // set players coords
		td->setCell(PChr->getSymbol(), r, c);
		pcChamber = cellAt(r,c)->getChamberNum();
    	loop = true;
    	// Alice edited: different methods for finding stairs 
    	if (filename == ""){
        	//generate stairs
        	while (td->isOccupied(r,c)||cellAt(r,c)->getChamberNum()==pcChamber){
            		r = rand()%25+1;
            		c = rand()%79+1;
        	}
		td->setCell(stairs, r, c);
    	}
    	else {
        	for (int i = 0; (i < 25) && loop; i++){
         	for (int j = 0; (j < 79) && loop; j ++){
           		if (td->getCell(i,j) == stairs){
              		r = i;
              		c = j;
              		loop = false;
           		}
         	}
        	}
    	}
	td->setCell(stairs, r, c);
    	loop = true;
	// generate potions
	if (filename == ""){
     	for (int i = 0; i < potLeft; potLeft--){
      randCham = rand()%5+1;
		while (td->isOccupied(r,c)
		     ||cellAt(r,c)->getChamberNum()!=randCham){
        	r = rand()%25+1;
        	c = rand()%79+1;
      }
      Item* item = createItem("potion", r, c);
      attachItemToCell(item, r, c);
      item->setCoords(r,c);
      td->setCell(item->getSymbol(), r, c);
		randCham = 0;
     	}
  	}
   else {
     	int count = 0;
     	char lowerBound = 48;
     	char upperBound = 53;
     	for (int i = 0; (i < 25) && (count < potLeft); i++){
        	for (int j = 0; (j < 79) && (count < potLeft); j ++){
           	tracker = td->getCell(i, j);
           	if ((lowerBound <= tracker) && (tracker <= upperBound)){
           		r = i;
           		c = j;
           		Item* item = 0;
            	if (td->getCell(i,j) == '0'){
                	item = new RestoreHealth;
              	}
              	else if (td->getCell(i, j) == '1'){
                	item = new BoostAtk;
              	}
              	else if (td->getCell(i, j) == '2'){
                 	item = new BoostDef;
              	}
              	else if (td->getCell(i, j) == '3'){
                 	item = new PoisonHP;
              	}
             	else if (td->getCell(i, j) == '4'){
                 	item = new WoundAtk;
              	}
              	else if (td->getCell(i, j) == '5'){
                 	item = new WoundDef;
              	}
				attachItemToCell(item, r, c);
            td->setCell(item->getSymbol(), r, c);
            count++;
            }
         }
    	}
    }
    // generate gold
    if (filename == ""){
     	for (int i = 0; i < goldLeft; goldLeft--){
		randCham = rand()%5+1;
        	while (td->isOccupied(r,c)||cellAt(r,c)->getChamberNum()!=randCham){
			r = rand()%25+1;
           	c = rand()%79+1;
        	}
         Item* item = createItem("treasure", r, c);
       	//attach to cell and set coords
        	td->setCell('G', r, c);
        	attachItemToCell(item,r,c);
        	item->setCoords(r,c);
			randCham = 0;
       	if (item->getType() == "Dragon Horde"){
        	// find an adjacent spot for the dragon
        	while ((tempC==0&&tempR==0)||td->isOccupied(r+tempR,c+tempC)){
        		tempC = rand()%3-1;
        		tempR = rand()%3-1;
        	}
         r+=tempR;
         c+=tempC;
         Dragon *d = new Dragon(item) ;		
         td->setCell('D',r,c);
         attachCharToCell(d,r,c);
         d->setCoords(r,c);
			enemyLeft--;
         tempC = 0;
         tempR = 0;
         }
     	}
    }
    else {
        int count = 0;
        char lowerBound = 54;
        char upperBound = 57;
        for (int i = 0; (i < 25) && (count < goldLeft); i++){
            for (int j = 0; (j < 79) && (count < goldLeft); j ++){
                tracker = td->getCell(i, j);
                if ((lowerBound <= tracker) && (tracker <= upperBound)){
                    r = i;
                    c = j;
                    Item* item = 0;
                    if (td->getCell(i,j) == '6'){
                        item = new Normal;
                    }
                    else if (td->getCell(i, j) == '7'){
                        item = new SmallHorde;
                    }
                    else if (td->getCell(i, j) == '8'){
                        item = new MerchantHorde;
                    }
                    else if (td->getCell(i,j) == '9'){
                        item = new DragonHorde;
                    }
                    attachItemToCell(item, r, c);
                    td->setCell(item->getSymbol(), r, c);
                    count++;
                }
            }
        }
    }
	// generate enemies, change to account for dragons
   if (filename == ""){
     	for (int i = 0; i < enemyLeft; enemyLeft--){
		randCham = rand()%5+1;
		while (td->isOccupied(r, c)
			||cellAt(r,c)->getChamberNum()!=randCham){
        	r = rand()%25+1;
        	c = rand()%79+1;
      }
      Character *enemy = createEnemy(r,c);
      attachCharToCell(enemy, r, c); // attachs this enemy to a cell
      enemy->setCoords(r,c);
      td->setCell(enemy->getSymbol(), r, c);
     	}
  	}
  	else {
     	char lowerBound = 68;
     	char upperBound = 88;
     	int count = 0;
     	for (int i = 0; (i < 25) && (count < enemyLeft); i++){
     		for (int j = 0; (j < 79) && (count < enemyLeft); j ++){
           	tracker = td->getCell(i, j);
           	if ((tracker != 'G' && tracker != 'P') && (lowerBound <= tracker) 
					&& (tracker <= upperBound)){
              	Character *enemy = 0;
              	r = i;
              	c = j;
              	if (td->getCell(i,j) == 'V'){
                 	enemy = new Vampire;
              	}
             	else if (td->getCell(i,j) == 'W'){
              		enemy = new Werewolf;
              	}
             	else if (td->getCell(i,j) == 'N'){
                	enemy = new Goblin;
              	}
              	else if (td->getCell(i,j) == 'M'){
                 	enemy = new Merchant;
              	}
               else if (td->getCell(i,j) == 'D'){
						cout << "dragon spawning" << endl;
                  enemy = new Dragon(playerPos(i,j));
              		cout << "dragon spawned" << endl;
					}
              	else if (td->getCell(i,j) == 'X'){
                 	enemy = new Phoenix;
              	}
              	else if (td->getCell(i,j) == 'T'){
                 	enemy = new Troll;
              	}
            	attachCharToCell(enemy, r, c);
              	enemy->setCoords(r, c);
              	count++;
           	}
         }
     	}
  	} 
}

void Floor::attachCharToCell(Character* chr, int r, int c){
	cellAt(r,c)->setChr(chr);
}

void Floor::attachItemToCell(Item* item, int r, int c){
	cellAt(r,c)->setItem (item);
}

void Floor:: printStats(){
   #ifndef BONUS 
	if (!Character::isDead() && !Floor::gameWon()){
        cout << "Race: " << PChr->getRace() << " Gold: " << setprecision(2) << fixed << PChr->getGold() << "                                                   Floor " << floorLevel << endl;
        cout << "HP: " << PChr->getHealth() << endl;
        cout << "Atk: " << PChr->getAttack() << endl;
        cout << "Def: " << PChr->getDefence() << endl;
        cout << "Action: " << action << endl;
    }
    else if (Floor::gameWon()){
        cout << "You Won!" << endl;
        if (PChr->getRace() == "human"){
            cout << "Score is: " << setprecision(2) << fixed << PChr->getGold() * 1.5 << endl;
        }
        else {
           cout << "Score is: " << setprecision(2) << fixed << PChr->getGold() << endl;
        }
    }
    else if (Character::isDead()) {
        cout << "Game Over." << endl;
        if (PChr->getRace() == "human"){
            cout << "Score is: " << setprecision(2) << fixed << PChr->getGold() * 1.5 << endl;
        }
        else {
           cout << "Score is: " << setprecision(2) << fixed << PChr->getGold() << endl;
        }
    }
	#endif

	#ifdef BONUS
	string race = PChr->getRace();
	double gold = PChr->getGold();
	int health = PChr->getHealth();
	int attack = PChr->getAttack();
	int defence = PChr->getDefence();
	if (!Character::isDead() && !Floor::gameWon()){
		move(24,0);
		printw("Race: %s     Gold: %.2f     Floor: %d\n", race.c_str(),gold,floorLevel);
		printw("HP: %d\n", health);
		printw("Atk: %d\n", attack);
		printw("Def: %d\n\n", defence);
		move(29,0);
		printw("Action: %s\n\n", action.c_str());
	}
	else if (Floor::gameWon()){
		printw("You Won!\n");
		if (race == "human"){
			printw("Score is: %.2f\n\n", gold*1.5);
		}
		else {
			printw("Score is: %.2f\n\n", gold);
		}
	}
	else if (Character::isDead()){
		printw("Game Over.\n");
		if (race == "human"){
			printw("Score is: %.2f\n\n", gold*1.5);
		}
		else {
			printw("Score is: %.2f\n\n", gold);
		}
	}
	#endif
   action = "";
}
// randomly generates an enemy except dragon
Character* Floor::createEnemy(int r, int c){
	int gen = 0;
	gen = rand()%18+1; // 1-18
	if (gen >= 16){
		Vampire *v = new Vampire;
		return v;
	}
	else if (gen >= 12) {
		Werewolf *w = new Werewolf;
		return w;
	}
	else if (gen >= 7){
		Goblin *g = new Goblin;
		return g;
	}
	else if (gen >= 5){
		Troll *t = new Troll;
		return t;
	}
	else if (gen >= 3){
		Merchant *m = new Merchant;
		return m;
	}
	else if (gen >= 1){
		Phoenix *p = new Phoenix;
		return p;
	}
	return NULL;
}


//Need to implement pure virtual method getEffect first
Item* Floor::createItem(string item, int r, int c){
	int gen = 0;
	if (item == "potion"){
		gen = rand()%6+1; // 1-6
		if (gen == 1){
			BoostAtk *p = new BoostAtk;
			return p;
		}
		else if (gen == 2){
			BoostDef *p = new BoostDef;
			return p;
		}
		else if (gen == 3){
			RestoreHealth *p = new RestoreHealth;
			return p;
		}
		else if (gen == 4){
			WoundDef *p = new WoundDef;
			return p;
		}
		else if (gen == 5){
			WoundAtk *p = new WoundAtk;
			return p;
		}
		else if (gen == 6){
			PoisonHP *p = new PoisonHP;
			return p;
		}
	}
	else if(item == "treasure"){
		gen = rand()%8+1; // 1 - 8
		if (gen >= 8){
			DragonHorde *t = new DragonHorde;
			return t;
		}
		else if (gen >= 6){
			Normal *t = new Normal;
			return t;
		}
		else if (gen >= 1){
			SmallHorde *t = new SmallHorde;
			return t;
		}
	}
	return NULL;
}


ostream &operator<< (ostream &out, const Floor &f){
	out << *f.td << endl;
	return out;
}

void updateCoords(string dir, int &r, int &c){
	if (dir == "no") { r--; }
	else if (dir == "ea") { c++; }
	else if (dir == "so") { r++; }
	else if (dir == "we") { c--; }
	else if (dir == "nw") { r--; c--; }
	else if (dir == "ne") { r--; c++; }
	else if (dir == "se") { r++; c++; }
	else if (dir == "sw") { r++; c--; }
}

void updateCoords(char dir, int &r, int &c){
	if (dir == 'w') { r--; }
	else if (dir == 'd') { c++; }
	else if (dir == 's') { r++; }
	else if (dir == 'a') { c--; }
	else if (dir == 'q') { r--; c--; }
	else if (dir == 'e') { r--; c++; }
	else if (dir == 'c') { r++; c++; }
	else if (dir == 'z') { r++; c--; }
}

string getStrDir(char dir){
	if (dir == 'w'){ return "no"; }
	else if (dir == 's') { return "so"; }
	else if (dir == 'd'){ return "ea"; }
	else if (dir == 'a'){ return "we"; }
	else if (dir == 'q') { return "nw"; }
	else if (dir == 'e'){ return "ne"; }
	else if (dir == 'z'){return "sw";}
	else if (dir == 'c'){ return "se";}
	else { return "no"; }
}

#ifndef BONUS
void Floor::movePC(string dir, int r, int c){
	//cout << "In movePC" << endl;
	
	Character *pc = PChr;
	int tempC = c;
	int tempR = r;
	updateCoords(dir, tempR, tempC);

	char obj = td->getCell(dir, r, c); // symbol on the grid
	if (obj == '.' || obj == '#' || obj == '+' || obj=='\\'||obj =='G'){
	// if the item is not lootable
	Item *item = cellAt(tempR, tempC)->getItem();
	if (item && !item->getLootable()){ 
		return;
	}
// stairs
	if (obj == '\\'){
		if ((floorLevel + 1) == 6){
			td->setCell(pc->getOnObj(), r, c);
			attachCharToCell(NULL, r, c);
			updateCoords(dir, r, c);
			Floor::setGameWon();
			return;
		}
		else {
			init("");
		}
	}
	else {
		td->setCell(pc->getOnObj(), r, c);
		attachCharToCell(NULL, r, c);
		updateCoords(dir, r, c); //update r and c depending on direction
         
		// on gold
		if (obj == 'G'){
			cellAt(r,c)->getItem()->getEffect(*pc);
			double amt = cellAt(r,c)->getItem()->getVal(*pc);
			string amount;
			ostringstream s;
			s << amt;
			amount = s.str();
			action = "Picked up " + amount + " pieces of Gold. ";
			pc->setOnObj('.');
		}
		else {
			pc->setOnObj(obj);
			action = "You made a move. ";
		}          
		td->setCell('@', r, c);
		PChr->setCoords(r,c);
		attachCharToCell(pc, r, c);
		}
	}
}
#endif

#ifdef BONUS
bool Floor::movePC(char pdir, int r, int c){
   string dir = getStrDir(pdir);
   Character *pc = PChr;
   int tempC = c;
   int tempR = r;
	int health;
   updateCoords(dir, tempR, tempC);

   char obj = td->getCell(dir, r, c); // symbol on the grid
	if (pdir == 'h'){
		health = PChr->getHealth() + 20;
		PChr->setHealth(health);
		action += "You heal 20 HP. ";
		return true;
	}
   // if the item is not lootable
	if (obj == '.' || obj == '#' || obj == '+' || obj == '\\' || obj == 'G'){
   	Item *item = cellAt(tempR, tempC)->getItem();
   	if (item && !item->getLootable()){
      	//cout << "Item not lootable" << endl;
      	return false;
   	}
      // stairs
      if (obj == '\\'){
			if ((floorLevel + 1) == 6){
				td->setCell(pc->getOnObj(), r, c);
				attachCharToCell(NULL, r, c);
				updateCoords(dir, r, c);
				Floor::setGameWon();
				return true;
			}
			else {
         	init("");
         	return true;
			}
      }
      else {
         td->setCell(pc->getOnObj(), r, c);
         attachCharToCell(NULL, r, c);
         updateCoords(dir, r, c); //update r and c depending on direction

         // on gold
         if (obj == 'G'){
            cellAt(r,c)->getItem()->getEffect(*pc);
            double amt = cellAt(r,c)->getItem()->getVal(*pc);
            string amount;
            ostringstream s;
            s << amt;
            amount = s.str();
            action = "Picked up " + amount + " pieces of Gold. ";
				pc->setOnObj('.');
         }
         else {
            pc->setOnObj(obj);
				action = "You made a move. ";
         }

         td->setCell('@', r, c);
         PChr->setCoords(r,c);
         attachCharToCell(pc, r, c);
      }
   return true;
   }
   else if (obj == 'P'){
      usePotion(dir, r, c);
      return true;
   }
   else if (obj == 'D' || obj == 'W' || obj == 'N' || obj == 'X' || obj == 'T'
       || obj == 'M' || obj == 'V'){
      attack(dir,r,c);
      return true;
   }
   return false;
}
#endif

// Use potion function
bool Floor::usePotion(string dir, int r, int c){
	updateCoords(dir,r,c);
	Item* item = cellAt(r,c)->getItem();
	if (item->getSymbol()=='P'){
		item->getEffect(*PChr);
		string type = item->getType();
		if (type == "Restore Health"){
			if (!RestoreHealth::isEncountered()){
				RestoreHealth::setEncounter(true);
				action = "Player drinks an unknown potion. ";
			}
			else {
				action = "Player drinks a health restoring potion - Health has been increased. ";
			}
		}
		else if (type == "Boost Attack"){
			if (!BoostAtk::isEncountered()){
				BoostAtk::setEncounter(true);
				action = "Player drinks an unknown potion. ";
			}
			else {
				action = "Player drinks an attack boosting potion - Attack has been increased. ";
			}
		}
		else if (type == "Boost Defence"){
			if (!BoostDef::isEncountered()){
				BoostDef::setEncounter(true);
				action = "Player drinks an unknown potion. ";
			}
			else {
				action = "Player drinks a defence boosting potion - Defence has been increased. ";
			}
		}
		else if (type == "Poison Health"){
			if (!PoisonHP::isEncountered()){
				PoisonHP::setEncounter(true);
				action = "Player drinks an unknown potion. ";
			}
			else {
				action = "Player drinks poison. Health has been decreased. ";
			}
		}
		else if (type == "Wound Attack"){
			if (!WoundAtk::isEncountered()){
				WoundAtk::setEncounter(true);
				action = "Player drinks an unknown potion. ";
			}
			else {
				action = "Player drinks an attack wounding potion - Attack has been decreased. ";
			}
		}
		else if (type == "Wound Defence"){
			if (!WoundDef::isEncountered()){
				WoundDef::setEncounter(true);
				action = "Player drinks an unknown potion. ";
			}
			else {
				action = "Player drinks a defence wounding potion - Defence has been decreased. ";
			}
		}
		if(PChr->getHealth() == 0){
			Character::setDead();
			return true;
		}
		potions.push_back(item);
		attachItemToCell(NULL, r, c);
		td->setCell('.', r, c);
		return true;
	}
	return false; //if the use failed
}


bool Floor::isNeighbour(char sym, int r, int c){
    if (td->getCell(r-1, c-1) == sym){
        return true;
    }
    else if (td->getCell(r-1, c) == sym){
        return true;
    }
    else if (td->getCell(r-1, c+1) == sym){
        return true;
    }
    else if (td->getCell(r, c-1) == sym){
        return true;
    }
    else if (td->getCell(r, c+1) == sym){
       	return true;
    }
    else if (td->getCell(r+1, c-1) == sym){
        return true;
    }
    else if (td->getCell(r+1, c) == sym){
        return true;
    }
    else if (td->getCell(r+1, c+1) == sym){
        return true;
    }
    
    return false;
}

void Floor::attack(string dir, int r, int c){
    //	cout << "Player coords:" << r << " " << c << endl;
	double damageEne = 0;
    	updateCoords(dir, r, c); 
	char cellSym = td->getCell(r,c);
	// attacking nothing
	if (cellSym == '|' || cellSym == '-'|| cellSym == '.' || cellSym == '+' 
	    || cellSym == '#'|| cellSym == 'P' || cellSym == 'G' || cellSym == ' ') {
		action = "You attacked the air with all your might. ";
		return;	
	}
   Character* ene = cellAt(r,c)->getChr();
	char eSym = ene->getSymbol();
		if (eSym == 'T' || eSym == 'V' || eSym == 'W' || eSym == 'X' || eSym == 'N' || eSym == 'D' || eSym == 'M'){
        	if (eSym == 'M'){
         	Merchant::setAngry();
				action = "You attacked a merchant. ";		
        	}
			else if (eSym == 'T'){
				action = "You attacked a troll. ";
			}
			else if (eSym == 'V'){
				action = "You attacked a vampire. ";
			}
			else if (eSym == 'W'){
				action = "You attacked a werewolf. ";
			}
			else if (eSym == 'X'){
				action = "You attacked a phoenix. ";
			}
			else if (eSym == 'N'){
				action = "You attacked a goblin. ";
			}
			else if (eSym == 'D'){
				action = "You attacked a dragon. ";
			}
      	damageEne = ene->getDamage(PChr);
			int newHP = ene->getHealth() - damageEne;
       	ene->setHealth(newHP);
    	}
    	if (ene->getHealth() == 0){
			if (PChr->getRace() == "dwarf"){
				PChr->setGold(PChr->getGold() + (2 * ene->getGold()));
				action = "Dwarf has been slain. ";
			}
			else if (PChr->getRace() == "orc"){
				PChr->setGold(PChr->getGold() + (ene->getGold() / 2));
				action ="Orc has been slain. ";
			}
			else if (ene->getSymbol() == 'M'){
				attachItemToCell(new MerchantHorde, r, c);
				attachCharToCell(NULL,r,c);
				td->setCell('G', r, c);
				action = "Merchant has been slain. ";
				return; 
			}
			else if (ene->getSymbol() == 'T'){
			   action = "Troll has been slain. ";
         }
         else if (eSym == 'V'){
            action = "Vampire has been slain. ";
         }
         else if (eSym == 'W'){
            action = "Werewolf has been slain. ";
         }
         else if (eSym == 'X'){
            action = "Phoenix has been slain. ";
         }
         else if (eSym == 'N'){
            action = "Goblin has been slain. ";
         }
         else if (eSym == 'D'){
            action = "Dragon has been slain. ";
         }
			else {
        		PChr->setGold(PChr->getGold() + ene->getGold());
			}
		attachCharToCell(NULL, r, c);
        	td->setCell('.', r, c);
    	}   
	// needs to check if pc's health = 0 after each round
}

// moves enemy assuming row r and col c is not occupied
// the coords are coords of the enemy
void Floor::moveEnemy(Character* enemy, int r, int c){
	int randX = 0; // -1 to 1
	int randY = 0; // -1 to 1
	// loop to find open position
	if (enemy->getSymbol()=='D') { return; }
	while ((randX==0&&randY==0)||td->isOccupied(randX+r,randY+c)){
		randX = rand()%3-1;
		randY = rand()%3-1;
	}
	td->setCell('.',r,c);
	attachCharToCell(NULL, r, c); // detach the enemy from cell
	r += randX;
	c += randY;
	td->setCell(enemy->getSymbol(),r,c);
	enemy->setCoords(r,c);
	attachCharToCell(enemy,r,c);
}

void Floor::enemyReact(){
   int x, y, damage, atk, newHP;
   bool foundPlayer = false;
   bool nearChest = false;
   bool attacked = false;
	bool canAtk = false;
	bool hasSpot = false;
	int dhC, dhR;
    	srand(time(0));
    	storeEnemies(); //we need to store all enemies each time since they may have moved/died
   for (int i = 0; i < enemies.size(); i++){
     	Character* e = enemies[i];
     	x = e->getR();
     	y = e->getC();
     	atk = rand()%2;
        	foundPlayer = isNeighbour(PChr->getSymbol(), x, y);
        	if (foundPlayer){
			attacked = false;
           	if (e->getSymbol() == 'M'){
					canAtk = Merchant::getAngry();
					attacked = canAtk;
				}
				else if (e->getSymbol() == 'D'){
					dhR = e->getItem()->getR();
					dhC = e->getItem()->getC();
					// these are coordinates for dragon not chest
					canAtk = isNeighbour(PChr->getSymbol(), dhR, dhC);
				}	       
				else {
					canAtk = true;
				}
				if (atk == 1 && canAtk){
					damage = PChr->getDamage(e);
            	PChr->setHealth(PChr->getHealth() - damage);
					action += "A " +  e->getRace() + " attacked you. ";
					foundPlayer = false;
					if (PChr->getHealth() == 0){
       				Character::setDead();
           			return;
        			}
					attacked = true;  
        		}
				else if (canAtk){
					action += e->getRace() + " missed an attack. ";
					attacked = true;
				}
     		}
			// move enemy if it didn't attack
         if (!canAtk){
				hasSpot = isNeighbour('.',x,y);
				if (hasSpot){
	        		moveEnemy(e,x,y);
				}
	    	}
			canAtk = false;
    	}
	// we clear the enemies vector because their positions have changed, may have died
	enemies.clear();
}

// finds all enemies in the current floor and stores it in [enemies]
void Floor::storeEnemies(){
	for (int i = 0; i < cells.size(); i++){
		Character *e = cells[i]->getChr();
		if (e && e->getSymbol() != '@'){
			enemies.push_back(e);
		}
	}
}


// returns pointer to cell at row r and column c
Cell*Floor::cellAt(int r, int c){
	for (int i = 0; i < cells.size(); i++){
		if (cells[i]->getR() == r && cells[i]->getC() == c){
			return cells[i];
		}
	}
	return NULL;
}

bool Floor::notWall(char ch){
  	char lowerNum = 48;
  	char upperNum = 57;
  	char lowerEne = 68;
  	char upperEne = 88;
 	return (ch == '.'|| ch == '\\' || ch == '@' || ((lowerNum <= ch) 
		&& (ch <= upperNum)) || ((lowerEne <= ch) && (ch <= upperEne)));
}

void Floor::findChambers(string *display){
	int horiWall;
	int vertWall;
	int tempWall;
	int newXStart;
	Cell* cell;
	int chamberNum = 1;
	bool end = false;
	string grid [25];
	for (int i = 0; i < 25; i++){
		grid[i] = display[i];
	}
	for (int i = 1; i < 24; i++){
        for (int j = 1; j < 78; j++){
            // find the corner of chamber
            if (grid[i][j] == '|' && grid[i][j+1] == '-'){
		//cout << "New chamber found" << endl;
                grid[i][j] = 'X';
                vertWall = i+1;
                horiWall = j;
                newXStart = j;
                // go down and right until end
                while ((grid[vertWall][horiWall]=='|'||grid[vertWall][horiWall]=='+')
                       && !end){
                    // keep moving right for '.'
                    if (notWall(grid[vertWall][horiWall+1])
                        && grid[vertWall][horiWall-1]!='-'){
                        horiWall++;
                        while (notWall(grid[vertWall][horiWall])){
                            cell = cellAt(vertWall,horiWall);
                            cell->setChamberNum(chamberNum);
                            grid[vertWall][horiWall] = 'x';
                            horiWall++;
                        }
								grid[vertWall][horiWall] = 'O';
                        horiWall = newXStart;
                        vertWall ++;
                    }
                    // keep moving right if next unit is '-'
                    else if (grid[vertWall][horiWall+1] == '-'){
                        horiWall++;
                        while (grid[vertWall][horiWall] == '-'
                               || grid[vertWall][horiWall] == '+') {
                            grid[vertWall][horiWall] = 'x';
                            horiWall++;
                        }
                        // kinked wall
                        if (grid[vertWall][horiWall] == '|' &&
                            notWall(grid[vertWall][horiWall+1])){
                            newXStart = horiWall;
                        }
                        else {
                            end = true;
                        }
                    }
                    // backwards wall
                    else if (grid[vertWall][horiWall-1] == '-' &&
                             notWall(grid[vertWall][horiWall+1])){
                        tempWall = horiWall + 1;
                        while (notWall(grid[vertWall][tempWall])){
                            grid[vertWall][tempWall] = 'x';
                            cell = cellAt(vertWall, tempWall);
                            cell->setChamberNum(chamberNum);
                            tempWall ++;
                        }
                        horiWall = newXStart-1;
                        // go backwards until we reach a '|'
                        while (grid[vertWall][horiWall] == '-'||
                               grid[vertWall][horiWall] == '+'){
                            grid[vertWall][horiWall] = 'x';
                            horiWall--;
                        }
                        newXStart = horiWall;
                        vertWall++; // moves down the chamber wall
                    }
                }
                chamberNum++;
                end = false;
            }				
 	    }
	}
}
