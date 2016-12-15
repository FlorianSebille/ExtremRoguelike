all: Rogue clean

Rogue: GenWindow.o test_taille_terminal.o sauvegarde.o Affichage.o RandomRoom.o Placer_element.o Depl_perso.o porte_ou_escalier.o file.o Ask_Load_Save.o Charger_Sauvegarde.o debut_partie.o fin_de_la_partie.o monstre.o combat.o Rogue.o
	gcc -o Rogue -g GenWindow.o test_taille_terminal.o sauvegarde.o Affichage.o RandomRoom.o Placer_element.o Depl_perso.o porte_ou_escalier.o file.o Ask_Load_Save.o Charger_Sauvegarde.o debut_partie.o fin_de_la_partie.o monstre.o combat.o Rogue.o -lncurses -lm

GenWindow.o: GenWindow.c
	gcc -c GenWindow.c

test_taille_terminal.o: test_taille_terminal.c
	gcc -c test_taille_terminal.c

sauvegarde.o: sauvegarde.c
	gcc -c sauvegarde.c

file.o: file.c
	gcc -c file.c

Affichage.o: Affichage.c
	gcc -c Affichage.c

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

debut_partie.o: debut_partie.c
	gcc -c debut_partie.c

fin_de_la_partie.o: fin_de_la_partie.c
	gcc -c fin_de_la_partie.c

combat.o: combat.c
	gcc -c combat.c

monstre.o: monstre.c
	gcc -c monstre.c

Rogue.o: Rogue.c
	gcc -c Rogue.c

clean:
	rm *.o
