#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>
#include "GenWindow.h"
#define TAILLE 100


void ecrire_chat(WINDOW *chatwin, int *ligne, position_perso){

  int lignemax;
  int colonemax;

  int heightT = (int) LINES * 0.85;
  int widthT = (int) COLS * 0.2;

  int startyT = 2 ;	/* Dimensions et Position de la 3ème fenêtre */
  int startxT = (int) COLS * 0.697  ;

  getmaxyx(chatwin,lignemax,colonemax);

  if(*ligne >= lignemax-1){

    destroy_win(chatwin);
    chatwin = create_newwin(heightT,widthT,startyT,startxT,"Chat");
    *ligne = 1;

  }
  switch (position_perso) {
    case 0: mvwprintw(chatwin,*ligne,1,"deplacer vous avec les fleches vers la porte");
    case 1: mvwprintw(chatwin,*ligne,1,"vous etes sur une porte appuier sur entrer pour changer de salle");
    case 2: mvwprintw(chatwin,*ligne,1,"vous etes près d'un monstre vous pouver l'atacker et fuier");
    case 3: mvwprintw(chatwin,*ligne,1,"vous etes mort, vous etes nul");
    case 4: mvwprintw(chatwin,*ligne,1,"vous avez de la chance vous avez gagnez");
    //case ?: ;
  }
  *ligne = *ligne + 1;
  wrefresh(chatwin);
}
