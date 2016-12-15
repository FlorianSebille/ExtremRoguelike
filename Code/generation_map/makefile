all: Rogue clean

Rogue: GenWindow.o Rogue.o
	gcc -o Rogue GenWindow.o Rogue.o -lncurses

GenWindow.o: GenWindow.c
	gcc -c GenWindow.c

Rogue.o: Rogue.c fichierh/GenWindow.h
	gcc -c -I Rogue.c ./fichierh

clean:
	rm *.o
