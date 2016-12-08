
#include "total.h"

void Win_Stat(WINDOW *F_win, int widthF){
	int n;
	int MAX_HP = 5836;
	int MAX_FOOD = 10;
	wattron(F_win, A_BOLD | COLOR_PAIR(1));
	mvwprintw(F_win,2,2, "USER");
	n = strlen(joueur.nom);
	mvwprintw(F_win,2,widthF-1-n,"%s", joueur.nom);
	mvwprintw(F_win,3,2,"STAGE");
	n = log10(joueur.STAGE) + 1;
	mvwprintw(F_win,3,widthF-1-n,"%i", joueur.STAGE);
	wattroff(F_win, A_BOLD | COLOR_PAIR(1));
	wattron(F_win, A_BOLD | COLOR_PAIR(2));
	mvwprintw(F_win,6,2, "STATS:");
	mvwprintw(F_win,7,2,"LEVEL");
	n = log10(joueur.LEVEL) + 1;
	mvwprintw(F_win,7,widthF-1-n,"%i", joueur.LEVEL);
	//wbkgd(F_win, COLOR_PAIR(1)); colorier toute la fenêtre
	if(joueur.EXP == 0){
		mvwprintw(F_win,8,widthF-2,"0");
	}
	mvwprintw(F_win,8,2,"EXP");
	n = log10(joueur.EXP) + 1;
	mvwprintw(F_win,8,widthF-1-n,"%i", joueur.EXP);
	mvwprintw(F_win,9,2,"MAX HP");
	n = log10(MAX_HP) + 1;
	mvwprintw(F_win,9,widthF-1-n,"%i", MAX_HP);
	mvwprintw(F_win,10,2,"HP");
	n = log10(joueur.HP) + 1;
	mvwprintw(F_win,10,widthF-1-n,"%i", joueur.HP);
	mvwprintw(F_win,11,2,"ATT");
	n = log10(joueur.ATT) + 1;
	mvwprintw(F_win,11,widthF-1-n,"%i", joueur.ATT);
	mvwprintw(F_win,12,2,"DEF");
	n = log10(joueur.DEF) + 1;
	mvwprintw(F_win,12,widthF-1-n,"%i", joueur.DEF);
	mvwprintw(F_win,13,2,"MAX FOOD");
	n = log10(MAX_FOOD) + 1;
	mvwprintw(F_win,13,widthF-1-n,"%i", MAX_FOOD);
	mvwprintw(F_win,14,2,"FOOD");
	n = log10(joueur.FOOD) + 1;
	mvwprintw(F_win,14,widthF-1-n,"%i", joueur.FOOD);
	if(joueur.addcle == 1){
		wattroff(F_win, A_BOLD | COLOR_PAIR(2));
		wattron(F_win, A_BOLD | COLOR_PAIR(1));
		mvwprintw(F_win,16,2,"KEY");
		wattroff(F_win, A_BOLD | COLOR_PAIR(1));
		wattron(F_win, A_BOLD | COLOR_PAIR(2));
	}
	mvwprintw(F_win,21,2,"COMMAND: ");
	mvwprintw(F_win,22,2,"QUIT");
	n = strlen("Q");
	mvwprintw(F_win,22,widthF-1-n,"Q");
	mvwprintw(F_win,23,2,"SAVE");
	n = strlen("S");
	mvwprintw(F_win,23,widthF-1-n,"S");
	mvwprintw(F_win,25,2,"MOVE:");
	n = strlen("UPWARDS ARROW");
	mvwprintw(F_win,26,widthF-1-n,"UPWARDS ARROW");
	n = strlen("DOWNWARDS ARROW");
	mvwprintw(F_win,27,widthF-1-n,"DOWNWARDS ARROW");
	n = strlen("RIGHTWARDS ARROW");
	mvwprintw(F_win,28,widthF-1-n,"RIGHTWARDS ARROW");
	n = strlen("LEFTWARDS ARROW");
	mvwprintw(F_win,29,widthF-1-n,"LEFTWARDS ARROW");
	mvwprintw(F_win,26,2,"UP");
	mvwprintw(F_win,27,2,"DOWN");
	mvwprintw(F_win,28,2,"RIGHT");
	mvwprintw(F_win,29,2,"LEFT");
	wattroff(F_win, A_BOLD | COLOR_PAIR(2));
	wrefresh(F_win);
}
