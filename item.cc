#include "item.h"
#include <ctime>
#include <cstdlib>
using namespace std;

Item::Item(int num, char sym, bool loot): value(num), symbol(sym), lootable(loot){}

int Item::randVal(){
	srand(time(0));
	return rand()%10+1; //1-10	
}

void Item::setLootable(bool l){
	lootable = true;
}
