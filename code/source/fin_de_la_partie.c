#include "total.h"

int fin_game(WINDOW *chat_Win,WINDOW *map_Win,WINDOW *stat_Win){
	int startx, starty, width, height;
	WINDOW *fin_Win;
	cbreak();
	keypad(stdscr,TRUE);
	timeout(0);
	int choix;
	height = 31;
	width = 90;
	startx = 39;
	starty = 2;
  effacer_fenetre(map_Win);
	fin_Win=create_newwin(height,width,starty,startx,"FIN");
	mvwprintw(map_Win,2,2,"Vous avez gagner la partie voulez vous rejouer ou quitter");
	mvwprintw(map_Win,6,5,"LEFTWARDS ARROW: QUITTER");
	mvwprintw(map_Win,6,40,"RIGHTWARDS ARROW: REJOUER");
	wrefresh(map_Win);
	do{
		choix = getch();
	}while(choix != KEY_RIGHT && choix != KEY_LEFT);
	if(choix == KEY_RIGHT){
    effacer_fenetre(stat_Win);
    effacer_fenetre(chat_Win);
    effacer_fenetre(map_Win);
	}
  if(choix == KEY_RIGHT){
    return 1;
  }else return 0;
}
