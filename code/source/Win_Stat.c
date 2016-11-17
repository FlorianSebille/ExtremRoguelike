#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>

#define COLOR_BLACK   0
#define COLOR_RED     1
#define	COLOR_GREEN   2
#define	COLOR_YELLOW  3
#define	COLOR_BLUE    4
#define	COLOR_MAGENTA 5
#define	COLOR_CYAN    6
#define COLOR_WHITE   7

void Win_Stat(WINDOW *F_win){
	WINDOW * window;
	initscr();
	//use_default_colors();
	start_color();
	init_pair(1,COLOR_WHITE,COLOR_GREEN);
	init_pair(2,COLOR_RED, COLOR_BLACK);
	curs_set(0);
	noecho();
	wattron(F_win, COLOR_PAIR(2));
	use_default_colors();
	mvwprintw(F_win,2,2,"LEVEL");
	mvwprintw(F_win,3,2,"EXP");
	mvwprintw(F_win,5,2,"");
	attron(A_BOLD);
  	mvaddstr(0, 0, "Colour      FD  FB  FW  BG  BD    BFD BFB BFW BBG BBN");
  	attroff(A_BOLD);
}
