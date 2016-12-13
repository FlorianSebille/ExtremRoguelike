/**
 * \file GenWindow.c
 * \brief Création d'une fenêtre
 * \author LARDY Anthony
 * \author TROTTIER Arthur
 * \author SEBILLE Florian
 * \version 1.0.1
 */

#include "total.h"

/**
  * \brief Création d'une fenêtre
  * \fn WINDOW * create_newwin(int height, int width, int starty, int startx, char * label)
  * \param height Hauteur de la fenêtre
  * \param width Largeur de la fenêtre
  * \param starty Début de la fenêtre sur l'axe des y
  * \param startx Début de la fenêtre sur l'axe des x
  * \param label Nom de la fenêtre
  */

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


/**
  * \brief Destruction d'une fenêtre
  * \fn void destroy_win(WINDOW *local_win)
  * \param local_win Fenêtre que l'on souhaite supprimer
  */

void destroy_win(WINDOW *local_win)
{
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}
