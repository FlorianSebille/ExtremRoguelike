#include "total.h"

void affichage(t_cellule MAP [x] [y], WINDOW *fenetre){

  int i,max_i,j,max_j;
  getmaxyx(fenetre,max_i,max_j);

  for(i = 0; i < max_i; i++){
    for(j = 0; j < max_j; j++){
      if(MAP[i][j].lieu == 0){
        mvwprintw(fenetre,i,j," ");
      }else if(MAP[i][j].lieu == 1){
        mvwprintw(fenetre,i,j,"+");
      }else if(MAP[i][j].lieu == 2){
        mvwprintw(fenetre,i,j,"*");
      }
    }
  }
  wrefresh(fenetre);
}
