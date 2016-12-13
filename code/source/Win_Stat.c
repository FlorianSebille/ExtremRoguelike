
#include "total.h"

void Win_Stat(WINDOW *F_win, int widthF){
	int n;
	int MAX_HP = 20;
	int MAX_FOOD = 10;
	effacer_fenetre(F_win);
	wattron(F_win, A_BOLD | COLOR_PAIR(1));
	mvwprintw(F_win,2,2, "NOM");
	n = strlen(joueur.nom);
	mvwprintw(F_win,2,widthF-1-n,"%s", joueur.nom);
	mvwprintw(F_win,3,2,"ETAGE");
	n = log10(joueur.STAGE) + 1;
	mvwprintw(F_win,3,widthF-1-n,"%i", joueur.STAGE);
	wattroff(F_win, A_BOLD | COLOR_PAIR(1));
	wattron(F_win, A_BOLD | COLOR_PAIR(2));
	mvwprintw(F_win,5,2, "STATS:");
	wattroff(F_win, A_BOLD | COLOR_PAIR(2));
	mvwprintw(F_win,6,4,"NIVEAU");
	n = log10(joueur.LEVEL) + 1;
	wattron(F_win, A_BOLD | COLOR_PAIR(2));
	mvwprintw(F_win,6,widthF-1-n,"%i", joueur.LEVEL);
	wattroff(F_win, A_BOLD | COLOR_PAIR(2));
	//wbkgd(F_win, COLOR_PAIR(1)); colorier toute la fenêtre
	if(joueur.EXP == 0){
		mvwprintw(F_win,7,widthF-2,"0");
	}
	mvwprintw(F_win,7,4,"EXP");
	n = log10(joueur.EXP) + 1;
	wattron(F_win, A_BOLD | COLOR_PAIR(2));
	mvwprintw(F_win,7,widthF-1-n,"%i", joueur.EXP);
	wattroff(F_win, A_BOLD | COLOR_PAIR(2));
	mvwprintw(F_win,8,4,"HP");
	n = log10(joueur.HP) + 1;
	if(joueur.HP <= 5){
		wattron(F_win, A_BOLD | COLOR_PAIR(1));
	}else wattron(F_win, A_BOLD | COLOR_PAIR(2));
	if(joueur.HP == 0){
		mvwprintw(F_win,8,widthF-2,"0");
	}else mvwprintw(F_win,8,widthF-1-n,"%i", joueur.HP);
	if(joueur.HP <= 5){
		wattroff(F_win, A_BOLD | COLOR_PAIR(1));
	}else wattroff(F_win, A_BOLD | COLOR_PAIR(2));
	mvwprintw(F_win,9,4,"ATT");
	n = log10(joueur.ATT) + 1;
	wattron(F_win, A_BOLD | COLOR_PAIR(2));
	mvwprintw(F_win,9,widthF-1-n,"%i", joueur.ATT);
	wattroff(F_win, A_BOLD | COLOR_PAIR(2));
	mvwprintw(F_win,10,4,"DEF");
	n = log10(joueur.DEF) + 1;
	wattron(F_win, A_BOLD | COLOR_PAIR(2));
	mvwprintw(F_win,10,widthF-1-n,"%i", joueur.DEF);
	wattroff(F_win, A_BOLD | COLOR_PAIR(2));

	mvwprintw(F_win,11,4,"FAIM");
	n = log10(joueur.FOOD) +1;
	if(joueur.FOOD <= 5){
		wattron(F_win, A_BOLD | COLOR_PAIR(1));
	}else wattron(F_win, A_BOLD | COLOR_PAIR(2));
	if(joueur.FOOD == 0){
		mvwprintw(F_win,11,widthF-2,"0");
	}else mvwprintw(F_win,11,widthF-1-n,"%i", joueur.FOOD);
	if(joueur.FOOD <= 5){
		wattroff(F_win, A_BOLD | COLOR_PAIR(1));
	}else wattroff(F_win, A_BOLD | COLOR_PAIR(2));


	if(joueur.addcle == 1){
		wattroff(F_win, A_BOLD | COLOR_PAIR(2));
		wattron(F_win, A_BOLD | COLOR_PAIR(1));
		mvwprintw(F_win,13,2,"KEY");
		wattroff(F_win, A_BOLD | COLOR_PAIR(1));
	}
	wattron(F_win, A_BOLD | COLOR_PAIR(2));
	mvwprintw(F_win,15,2,"COMMAND: ");
	wattroff(F_win, A_BOLD | COLOR_PAIR(2));
	mvwprintw(F_win,16,4,"NOURRITURE");
	n = strlen("f");
	wattron(F_win, A_BOLD | COLOR_PAIR(1));
	mvwprintw(F_win,16,widthF-1-n,"f");
	wattroff(F_win, A_BOLD | COLOR_PAIR(1));
	mvwprintw(F_win,17,4,"CLE");
	n = strlen("K");
	wattron(F_win, A_BOLD | COLOR_PAIR(1));
	mvwprintw(F_win,17,widthF-1-n,"K");
	wattroff(F_win, A_BOLD | COLOR_PAIR(1));
	mvwprintw(F_win,18,4,"MEDIKIT");
	n = strlen("M");
	wattron(F_win, A_BOLD | COLOR_PAIR(1));
	mvwprintw(F_win,18,widthF-1-n,"M");
	wattroff(F_win, A_BOLD | COLOR_PAIR(1));
	mvwprintw(F_win,19,4,"ESCALIER");
	n = strlen("f");
	wattron(F_win, A_BOLD | COLOR_PAIR(1));
	mvwaddch(F_win, 19, widthF-1-n, ACS_PI);
	wattroff(F_win, A_BOLD | COLOR_PAIR(1));
	mvwprintw(F_win,20,4,"ARRIVE");
	n = strlen("f");
	wattron(F_win, A_BOLD | COLOR_PAIR(2));
	mvwaddch(F_win, 20, widthF-1-n, ACS_CKBOARD);
	wattroff(F_win, A_BOLD | COLOR_PAIR(2));

	wattron(F_win, A_BOLD | COLOR_PAIR(2));
	mvwprintw(F_win,22,2,"COMMANDE: ");
	wattroff(F_win, A_BOLD | COLOR_PAIR(2));
	mvwprintw(F_win,23,4,"QUITTER");
	n = strlen("Q");
	mvwprintw(F_win,23,widthF-1-n,"Q");
	mvwprintw(F_win,24,4,"SAUVEGARDER");
	n = strlen("S");
	mvwprintw(F_win,24,widthF-1-n,"S");
	wattron(F_win, A_BOLD | COLOR_PAIR(2));
	mvwprintw(F_win,25,2,"MOVE:");
	wattroff(F_win, A_BOLD | COLOR_PAIR(2));
	n = strlen("FLECHE   HAUT");
	mvwprintw(F_win,26,widthF-1-n,"FLECHE   HAUT");
	n = strlen("FLECHE    BAS");
	mvwprintw(F_win,27,widthF-1-n,"FLECHE    BAS");
	n = strlen("FLECHE DROITE");
	mvwprintw(F_win,28,widthF-1-n,"FLECHE DROITE");
	n = strlen("FLECHE GAUCHE");
	mvwprintw(F_win,29,widthF-1-n,"FLECHE GAUCHE");
	mvwprintw(F_win,26,4,"HAUT");
	mvwprintw(F_win,27,4,"BAS");
	mvwprintw(F_win,28,4,"DROITE");
	mvwprintw(F_win,29,4,"GAUCHE");
	wattroff(F_win, A_BOLD | COLOR_PAIR(2));
	wrefresh(F_win);

}
