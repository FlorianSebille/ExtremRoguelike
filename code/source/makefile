all: Rogue clean

<<<<<<< HEAD
Rogue: GenWindow.o test_taille_terminal.o chat.o sauvegarde.o Win_Stat.o Rogue.o
	gcc -o Rogue GenWindow.o test_taille_terminal.o chat.o sauvegarde.o Win_Stat.o Rogue.o -lncurses
=======
Rogue: GenWindow.o Rogue.o RandomRoom.o AfficherMap.o
	gcc -o Rogue GenWindow.o Rogue.o RandomRoom.o AfficherMap.o -lncurses
>>>>>>> Branche-Arthur

GenWindow.o: GenWindow.c
	gcc -c GenWindow.c

test_taille_terminal.o: test_taille_terminal.c
	gcc -c test_taille_terminal.c

chat.o: chat.c
	gcc -c chat.c

sauvegarde.o: sauvegarde.c
	gcc -c sauvegarde.c

Win_Stat.o: Win_Stat.c
	gcc -c Win_Stat.c

Rogue.o: Rogue.c
	gcc -c Rogue.c

RandomRoom.o: RandomRoom.c
	gcc -c RandomRoom.c

AfficherMap.o: AfficherMap.c RandomRoom.c RandomRoom.h
	gcc -c AfficherMap.c RandomRoom.c

clean:
	rm *.o
