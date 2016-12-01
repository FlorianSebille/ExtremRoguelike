#include "total.h"

int Charger_Sauvegarde(){
	FILE * fic1;
	fic1 = fopen("Save.txt", "r");
	if(fic1 == NULL){
		WINDOW *Err_Win;
		int startxErr, startyErr, widthErr, heightErr;
		heightErr = LINES*0.33;
		widthErr = COLS*0.33;
		startxErr = COLS*0.33;
		startyErr = LINES*0.33;
		Err_Win=create_newwin(heightErr,widthErr,startyErr,startxErr,"Erreur");
		mvwprintw(Err_Win,5,widthErr*0.33,"Il n'existe pas de sauvegarde");
		mvwprintw(Err_Win,6,widthErr*0.30,"Une nouvelle partie va être chargé");
		wrefresh(Err_Win);
		sleep(2);
		effacer_fenetre(Err_Win);
		wborder(Err_Win, ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ');
		wrefresh(Err_Win);
		delwin(Err_Win);
		return KEY_RIGHT;
	}
	
	fclose(fic1);
}
	
