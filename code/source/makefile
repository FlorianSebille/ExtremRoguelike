all: Rogue clean

Rogue: GenWindow.o test_taille_terminal.o chat.o sauvegarde.o Win_Stat.o affichage_Swin.o RandomRoom.o Placer_element.o Depl_perso.o porte_ou_escalier.o file.o Ask_Load_Save.o Charger_Sauvegarde.o fin_de_la_partie.o Rogue.o
	gcc -o Rogue GenWindow.o test_taille_terminal.o chat.o sauvegarde.o Win_Stat.o affichage_Swin.o RandomRoom.o Placer_element.o Depl_perso.o porte_ou_escalier.o file.o Ask_Load_Save.o Charger_Sauvegarde.o fin_de_la_partie.o Rogue.o -lncurses -lm

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

affichage_Swin.o: affichage_Swin.c
	gcc -c affichage_Swin.c

file.o: file.c
	gcc -c file.c

RandomRoom.o: RandomRoom.c
	gcc -c RandomRoom.c

Placer_element.o: Placer_element.c
	gcc -c Placer_element.c

Depl_perso.o: Depl_perso.c
	gcc -c Depl_perso.c

porte_ou_escalier.o:porte_ou_escalier.c
	gcc -c porte_ou_escalier.c

Ask_Load_Save.o: Ask_Load_Save.c
	gcc -c Ask_Load_Save.c

Charger_Sauvegarde.o: Charger_Sauvegarde.c
	gcc -c Charger_Sauvegarde.c

fin_de_la_partie.o:fin_de_la_partie.c
	gcc -c fin_de_la_partie.c

Rogue.o: Rogue.c
	gcc -c Rogue.c

clean:
	rm *.o
