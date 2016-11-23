#include <ncurses.h>
#include "GenWindow.h"
#include "RandomRoom.h"
#include "AfficherMap.h"



int main(){

  initscr();

  int startxF, startyF, widthF, heightF;
  int startxS, startyS, widthS, heightS;
  int startxT, startyT, widthT, heightT;

  WINDOW * F_win;
  WINDOW * S_win;
  WINDOW * T_win;

  heightF = 31;   /* Dimensions et Position de la 1ère fenêtre */
  widthF = 22;
  startyF = 2 ;
  startxF = 5 ;

  heightS = 31;   /* Dimensions et Position de la 2ème fenêtre */
  widthS = 90;
  startyS = 2 ;
  startxS = 31 ;

  heightT = 31;    /* Dimensions et Position de la 3ème fenêtre */
  widthT = 36;
  startyT = 2 ;
  startxT = 125 ;

  refresh();

  F_win=create_newwin(heightF,widthF,startyF,startxF,"Profile");
  S_win=create_newwin(heightS,widthS,startyS,startxS,"Map");
  T_win=create_newwin(heightT,widthT,startyT,startxT,"Chat");


  getch();


  endwin();

}
