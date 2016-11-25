#include "total.h"


WINDOW * create_newwin(int height, int width, int starty, int startx, char * label)
{
  WINDOW *local_win;

	local_win = newwin(height, width, starty, startx); /* newwin() créer la fenêtre */

  wborder(local_win, '|', '|', '-','-','+','+','+','+'); /* Création des bordures */

	wmove(local_win,0,2);
	wprintw(local_win, label);

  wrefresh(local_win);    /* Affiche la fenêtre*/

	return local_win; /* Renvoi la fenêtre */
}

void destroy_win(WINDOW *local_win)
{
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}
