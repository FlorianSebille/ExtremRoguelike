#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>
#include "GenWindow.h"

int addsauv(WINDOW *centerwin){

  int choix;
  mvwprintw(centerwin,23,37,"voulez vous continuer la partie sauvegarder");
  mvwprintw(centerwin,25,37,"1: OUI");
  mvwprintw(centerwin,25,73,"2: NON");
  wrefresh(centerwin);
  choix = getch();
  return choix;
}
