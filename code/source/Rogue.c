#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>
#include "GenWindow.h"
<<<<<<< HEAD
#define TAILLE 100
=======
#include "Win_Stat.h"
>>>>>>> Xenos


int main(){

  initscr();
<<<<<<< HEAD
  noecho();
  if(taille_terminal()){

    int startxF, startyF, widthF, heightF;
    int startxS, startyS, widthS, heightS;
    int startxT, startyT, widthT, heightT;
    int ligne = 1;

    WINDOW * F_win;
    WINDOW * S_win;
    WINDOW * T_win;

    heightF = (int) LINES * 0.85;
    widthF =  (int) COLS * 0.12;
    startyF = 2 ;	/* Dimensions et Position de la 1ère fenêtre */
    startxF =  (int) COLS * 0.03 ;

    heightS = (int) LINES * 0.85;
    widthS =  (int) COLS * 0.5;
    startyS = 2 ;	/* Dimensions et Position de la 2ème fenêtre */
    startxS =  (int) COLS * 0.17 ;

    heightT = (int) LINES * 0.85;
    widthT = (int) COLS * 0.2;

    startyT = 2 ;	/* Dimensions et Position de la 3ème fenêtre */
    startxT = (int) COLS * 0.697 ;

    refresh();
    start_color();
    use_default_colors();

    F_win=create_newwin(heightF,widthF,startyF,startxF,"Profile");
    S_win=create_newwin(heightS,widthS,startyS,startxS,"Map");
    T_win=create_newwin(heightT,widthT,startyT,startxT,"Chat");

    Win_Stat(F_win,widthF);
    wrefresh(F_win);

    int position_perso = 0;
    while (getch() != 'q') {
      ecrire_chat(T_win,&ligne, position_perso);
      position_perso++;
      if (position_perso > 4) {
        position_perso = 0;
      }
    }
  }
  endwin();
}
