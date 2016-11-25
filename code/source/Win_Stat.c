#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "GenWindow.h"

void Win_Stat(WINDOW *F_win, int widthF){
	int n;
	int STAGE = 10;
	int LEVEL = 1;
	int EXP = 98484;
	int MAX_HP = 5836;
	int HP = 200 ;
	int ATT = 15;
	int DEF = 15;
	int MAX_FOOD = 10;
	int FOOD = 5 ;

	start_color();
	use_default_colors();
	init_pair(1, COLOR_RED, -1);
	init_pair(2, COLOR_GREEN, -1);
	noecho();
	wattron(F_win, A_BOLD | COLOR_PAIR(1));
	mvwprintw(F_win,3,2,"STAGE");
	mvwprintw(F_win,2,2, "USER");
	n = log10(STAGE) + 1;
	mvwprintw(F_win,3,widthF-1-n,"%i", STAGE);
	wattroff(F_win, A_BOLD | COLOR_PAIR(1));
	wattron(F_win, A_BOLD | COLOR_PAIR(2));
	mvwprintw(F_win,6,2, "STATS:");
	mvwprintw(F_win,7,2,"LEVEL");
	n = log10(LEVEL) + 1;
	mvwprintw(F_win,7,widthF-1-n,"%i", LEVEL);
	//wbkgd(F_win, COLOR_PAIR(1)); colorier toute la fenêtre
	mvwprintw(F_win,8,2,"EXP");
	n = log10(EXP) + 1;
	mvwprintw(F_win,8,widthF-1-n,"%i", EXP);
	mvwprintw(F_win,9,2,"MAX HP");
	n = log10(MAX_HP) + 1;
	mvwprintw(F_win,9,widthF-1-n,"%i", MAX_HP);
	mvwprintw(F_win,10,2,"HP");
	n = log10(HP) + 1;
	mvwprintw(F_win,10,widthF-1-n,"%i", HP);
	mvwprintw(F_win,11,2,"ATT");
	n = log10(ATT) + 1;
	mvwprintw(F_win,11,widthF-1-n,"%i", ATT);
	mvwprintw(F_win,12,2,"DEF");
	n = log10(DEF) + 1;
	mvwprintw(F_win,12,widthF-1-n,"%i", DEF);
	mvwprintw(F_win,13,2,"MAX FOOD");
	n = log10(MAX_FOOD) + 1;
	mvwprintw(F_win,13,widthF-1-n,"%i", MAX_FOOD);
	mvwprintw(F_win,14,2,"FOOD");
	n = log10(FOOD) + 1;
	mvwprintw(F_win,14,widthF-1-n,"%i", FOOD);
	mvwprintw(F_win,21,2,"COMMAND:");
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
