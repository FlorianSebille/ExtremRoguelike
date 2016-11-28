#include "total.h"

void affichage(t_cellule MAP [x] [y], WINDOW *fenetre){

  int i,max_i,j,max_j;
  getmaxyx(fenetre,max_i,max_j);

  for(i = 1; i < max_i -1; i++){
    for(j = 1; j < max_j -1; j++){
      if(MAP[i][j].lieu == vide){
        mvwprintw(fenetre,i,j," ");
      }else if(MAP[i][j].lieu == porte){
        mvwprintw(fenetre,i,j,"p");
      }else if(MAP[i][j].lieu == sol){
        mvwprintw(fenetre,i,j,".");
      }else if(MAP[i][j].lieu == mur){
        mvwprintw(fenetre,i,j,"+");
      }else if(MAP[i][j].lieu == personnage){
      	mvwprintw(fenetre,i,j,"@");
      }
    }
  }
  wrefresh(fenetre);
}
