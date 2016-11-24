all: Rogue clean

Rogue: GenWindow.o test_taille_terminal.o chat.o sauvegarde.o Rogue.o
	gcc -o Rogue GenWindow.o test_taille_terminal.o chat.o sauvegarde.o Rogue.o -lncurses

GenWindow.o: GenWindow.c
	gcc -c GenWindow.c

test_taille_terminal.o: test_taille_terminal.c
	gcc -c test_taille_terminal.c

chat.o: chat.c
	gcc -c chat.c

sauvegarde.o: sauvegarde.c
	gcc -c sauvegarde.c

Rogue.o: Rogue.c
	gcc -c Rogue.c

clean:
	rm *.o
