all: Rogue clean

Rogue: GenWindow.o test_taille_terminal.o chat.o sauvegarde.o Win_Stat.o affichage_Swin.o RandomRoom.o Placer_perso.o Rogue.o
	gcc -o Rogue GenWindow.o test_taille_terminal.o chat.o sauvegarde.o Win_Stat.o affichage_Swin.o RandomRoom.o Placer_perso.o Rogue.o -lncurses -lm

GenWindow.o: GenWindow.c
	gcc -c GenWindow.c

test_taille_terminal.o: test_taille_terminal.c
	gcc -c test_taille_terminal.c

chat.o: chat.c
	gcc -c chat.c

sauvegarde.o: sauvegarde.c
	gcc -c sauvegarde.c

Win_Stat.o: Win_Stat.c
	gcc -c Win_Stat.c -lm

affichage_Swin.o: affichage_Swin.c
	gcc -c affichage_Swin.c

RandomRoom.o: RandomRoom.c
	gcc -c RandomRoom.c

Rogue.o: Rogue.c
	gcc -c Rogue.c

Placer_perso.o: Placer_perso.c
	gcc -c Placer_perso.c

clean:
	rm *.o
