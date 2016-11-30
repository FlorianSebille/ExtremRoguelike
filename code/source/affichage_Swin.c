#include "total.h"

void affichage(t_cellule MAP [x] [y], WINDOW *fenetre){

  int i,max_i,j,max_j;
  getmaxyx(fenetre,max_i,max_j);

  for(i = 1; i < max_i -1; i++){
    for(j = 1; j < max_j -1; j++){
      if(MAP[i][j].lieu == vide){
        mvwprintw(fenetre,i,j,"%i",MAP[i][j].position);
      }else if(MAP[i][j].lieu == porte){
        wattron(fenetre, COLOR_PAIR(6));
        mvwprintw(fenetre,i,j," ");
        wattroff(fenetre, COLOR_PAIR(6));
      }else if(MAP[i][j].lieu == uplevel){
        wattron(fenetre, COLOR_PAIR(5));
        mvwaddch(fenetre, i, j, ACS_PI);
        wattroff(fenetre, COLOR_PAIR(5));
      }else if(MAP[i][j].lieu == sol){
        wattron(fenetre, COLOR_PAIR(4));
        mvwprintw(fenetre,i,j," ");
        wattroff(fenetre, COLOR_PAIR(4));
      }else if(MAP[i][j].lieu == mur){
        wattron(fenetre, COLOR_PAIR(4));
        mvwaddch(fenetre, i, j, ACS_CKBOARD);
        wattroff(fenetre, COLOR_PAIR(4));
      }else if(MAP[i][j].lieu == personnage){
        wattron(fenetre, COLOR_PAIR(3));
      	mvwprintw(fenetre,i,j,"@");
        wattroff(fenetre, COLOR_PAIR(3));
      }
    }
  }
  wrefresh(fenetre);
}
