#include "total.h"

int charger_sauvegarde(){
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
			if(choix!=ERR){
				switch(choix){
					case KEY_LEFT: choix = 1;break;
					case KEY_RIGHT: choix = 2;break;
				}
				if(choix = 1){
					mvwprintw(Save_Win,10,10,"1");
				}else if(choix = 2){
					mvwprintw(Save_Win,10,10,"2");
				}
			}
	}while(choix != 1 || choix != 2);	
	effacer_fenetre(Save_Win);
	return choix;
}
