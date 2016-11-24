#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>
#include "GenWindow.h"
#define TAILLE 100


int main(){

  initscr();
  noecho();
  if(taille_terminal()){

    int startxF, startyF, widthF, heightF;
    int startxS, startyS, widthS, heightS;
    int startxT, startyT, widthT, heightT;

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

    F_win=create_newwin(heightF,widthF,startyF,startxF,"Profile");
    S_win=create_newwin(heightS,widthS,startyS,startxS,"Map");
    T_win=create_newwin(heightT,widthT,startyT,startxT,"Chat");



    mvwprintw(F_win,2,2,"Bonjour");
    wrefresh(F_win);

    int ligne = 1;
    char key = getch();

    start_color();
    use_default_colors();

    while(key != 'q'){
      if(key == 'a'){
        char phrase[TAILLE]={"vous avez appuier sur a"};
        ecrire_chat(T_win,&ligne,phrase);
      }
      if(key == 'b'){
        char phrase[TAILLE]={"vous avez appuier sur b"};
        ecrire_chat(T_win,&ligne,phrase);
      }
      if(key == 'c'){
        char phrase[TAILLE]={"vous avez appuier sur c"};
        ecrire_chat(T_win,&ligne,phrase);
      }
      if(key == 'd'){
        char phrase[TAILLE]={"vous avez appuier sur d"};
        ecrire_chat(T_win,&ligne,phrase);
      }
      key = getch();
    }
    endwin();
  }
}
