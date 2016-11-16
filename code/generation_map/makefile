all: Rogue clean

Rogue: GenWindow.o Rogue.o
	gcc -o Rogue GenWindow.o Rogue.o -lncurses

GenWindow.o: GenWindow.c
	gcc -c GenWindow.c

Rogue.o: Rogue.c
	gcc -c Rogue.c

clean:
	rm *.o
	./Rogue
