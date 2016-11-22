all: Rogue clean

Rogue: GenWindow.o Rogue.o Win_Stat.o
	gcc -o Rogue GenWindow.o Rogue.o Win_Stat.o -lncurses -lm

GenWindow.o: GenWindow.c
	gcc -c GenWindow.c

Win_Stat.o: Win_Stat.c
	gcc -c Win_Stat.c
	
Rogue.o: Rogue.c
	gcc -c Rogue.c

clean:
	rm *.o
