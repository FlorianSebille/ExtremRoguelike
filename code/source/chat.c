#include "total.h"


void ecrire_chat(WINDOW *chatwin, int *ligne, int position_perso){

  int lignemax;
  int colonemax;

  int heightT = 31;    /* Dimensions et Position de la 3ème fenêtre */
  int widthT = 36;
  int startyT = 2 ;
  int startxT = 134 ;

  getmaxyx(chatwin,lignemax,colonemax);

  if(*ligne >= lignemax-1){

    destroy_win(chatwin);
    chatwin = create_newwin(heightT,widthT,startyT,startxT,"Chat");
    *ligne = 1;

  }

  switch (position_perso) { // pas plus de 44 caractere par commentaire dans le chat
    case 0: mvwprintw(chatwin,*ligne,1,"deplacer vous avec les fleches"); break;
    case 1: mvwprintw(chatwin,*ligne,1,"vous etes sur une porte"); break;
    case 2: mvwprintw(chatwin,*ligne,1,"vous etes près d'un monstre"); break;
    case 3: mvwprintw(chatwin,*ligne,1,"vous etes mort, vous etes nul"); break;
    case 4: mvwprintw(chatwin,*ligne,1,"vous avez gagnez, bien joue"); break;
    //case ?: ; break;
  }
  *ligne = *ligne + 2;
  wrefresh(chatwin);

}
