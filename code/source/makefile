all: Rogue clean

Rogue: GenWindow.o Rogue.o RandomRoom.o AfficherMap.o
	gcc -o Rogue GenWindow.o Rogue.o RandomRoom.o AfficherMap.o -lncurses

GenWindow.o: GenWindow.c
	gcc -c GenWindow.c

Rogue.o: Rogue.c
	gcc -c Rogue.c

RandomRoom.o: RandomRoom.c
	gcc -c RandomRoom.c

AfficherMap.o: AfficherMap.c RandomRoom.c RandomRoom.h
	gcc -c AfficherMap.c RandomRoom.c

clean:
	rm *.o
