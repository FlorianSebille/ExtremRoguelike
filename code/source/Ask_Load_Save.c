#include "total.h"

int Ask_Load_Save(){
	int startxSave, startySave, widthSave, heightSave;
	WINDOW *Save_Win;
	cbreak();
	keypad(stdscr,TRUE);
	timeout(0);
	int choix;
	heightSave = LINES*0.33;
	widthSave = COLS*0.33;
	startxSave = COLS*0.33;
	startySave = LINES*0.33;
	Save_Win=create_newwin(heightSave,widthSave,startySave,startxSave,"Sauvegarde");
	mvwprintw(Save_Win,2,2,"Voulez vous charger une partie sauvegardée ?");
	mvwprintw(Save_Win,6,widthSave*0.10,"LEFTWARDS ARROW: Oui");
	mvwprintw(Save_Win,6,widthSave*0.60,"RIGHTWARDS ARROW: Non");
	wrefresh(Save_Win);
	do{
		choix = getch();
	}while(choix != KEY_RIGHT && choix != KEY_LEFT);
	effacer_fenetre(Save_Win);
	wborder(Save_Win, ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ');
	wrefresh(Save_Win);
	delwin(Save_Win);
	return choix;
}
