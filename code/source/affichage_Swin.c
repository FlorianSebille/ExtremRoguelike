#include "total.h"

void affichage(WINDOW *fenetre){

  int i,max_i,j,max_j;
  getmaxyx(fenetre,max_i,max_j);

  for(i = 1; i < max_i -1; i++){
    for(j = 1; j < max_j -1; j++){
      if(MAP[i][j].lieu == vide){
        mvwprintw(fenetre,i,j," ");
      }else if(MAP[i][j].lieu == couloir){
        wattron(fenetre, COLOR_PAIR(6));
        mvwprintw(fenetre,i,j," ");
        wattroff(fenetre, COLOR_PAIR(6));
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
      }else if(MAP[i][j].lieu == piege){
        wattron(fenetre, COLOR_PAIR(5));
        mvwprintw(fenetre, i, j, "&");
        wattroff(fenetre, COLOR_PAIR(4));
      }else if(MAP[i][j].lieu == personnage){
        wattron(fenetre, COLOR_PAIR(3));
      	mvwprintw(fenetre,i,j,"@");
        wattroff(fenetre, COLOR_PAIR(3));
      }else if(MAP[i][j].lieu == arriver){
        wattron(fenetre, COLOR_PAIR(8));
      	mvwaddch(fenetre, i, j, ACS_CKBOARD);
        wattroff(fenetre, COLOR_PAIR(8));
      }else if(MAP[i][j].lieu == food){
        wattron(fenetre, COLOR_PAIR(7));
      	mvwprintw(fenetre, i, j,"f");
        wattroff(fenetre, COLOR_PAIR(7));
      }else if(MAP[i][j].lieu == cle){
        wattron(fenetre, COLOR_PAIR(7));
        mvwprintw(fenetre,i,j,"K");
      	//mvwaddch(fenetre, i, j, ACS_STERLING);
        wattroff(fenetre, COLOR_PAIR(7));
      }else if(MAP[i][j].lieu == mechant && monstre.HP > 0){
        wattron(fenetre, COLOR_PAIR(7));
        mvwprintw(fenetre,i,j,"T");
      }else if(MAP[i][j].lieu == medikit){
        wattron(fenetre, COLOR_PAIR(7));
      	mvwprintw(fenetre, i, j,"M");
        wattroff(fenetre, COLOR_PAIR(7));
      }
    }
  }
  wrefresh(fenetre);
}
