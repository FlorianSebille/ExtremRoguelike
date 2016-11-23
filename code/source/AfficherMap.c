#include <ncurses.h>
#include <stdlib.h>
#include "RandomRoom.h"

extern t_cellule MAP[100][200];

void Afficher(WINDOW * fenetre, int height, int width){
  int i,j;

  for(i = 0; i < height; i++){
    for(j = 0; j < width; j++){
      if(MAP[i][j].lieu == 0){
        mvwprintw(fenetre,i,j," ");
      }else if(MAP[i][j].lieu == 1){
        mvwprintw(fenetre,i,j,"+");
      }else if(MAP[i][j].lieu == 2){
        mvwprintw(fenetre,i,j,".");
      }
    }
  }
}
