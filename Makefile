CXX=g++
XXFLAGS=-Wall -MMD -g
EXEC=cc3k
OBJECTS= main.o textdisplay.o character.o floor.o human.o cell.o vampire.o werewolf.o item.o troll.o goblin.o phoenix.o merchant.o normal.o smallhorde.o merchanthorde.o dragonhorde.o restorehealth.o boostatk.o boostdef.o poisonhp.o woundatk.o wounddef.o dwarf.o elves.o orc.o dragon.o superman.o
DEPENDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${XXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC}
