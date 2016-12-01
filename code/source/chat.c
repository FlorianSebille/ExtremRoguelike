#include "total.h"

void effacer_ligne(WINDOW *chatwin, int ligne_effacer){
  int colone;
  int lignemax;
  int colonemax;

  getmaxyx(chatwin,lignemax,colonemax);

  for (colone = 1; colone < colone; colone++) {
    mvwprintw(chatwin,ligne_effacer,colone," ");
  }
}
void effacer_fenetre(WINDOW *chatwin){
  int ligne;
  int colone;
  int lignemax;
  int colonemax;

  getmaxyx(chatwin,lignemax,colonemax);

  for (ligne = 1; ligne < lignemax-1; ligne++) {
    for (colone = 1; colone < colonemax-1; colone++) {
      mvwprintw(chatwin,ligne,colone," ");
    }
  }
}

void ecrire_chat(WINDOW *chatwin, int position_perso){  // fonction qui ecrit dans la fenetre chat

  int lignemax;
  int colonemax;

  getmaxyx(chatwin,lignemax,colonemax); // optention du nombre de colone et de ligne de la troisieme colone
  effacer_fenetre(chatwin);

  // ecrit dans la fenetre en fonction de la position du perso
  mvwprintw(chatwin,1,1,"vous etes au niveau %i salle %i",joueur.STAGE,joueur.SALLE);
  switch (position_perso) { // pas plus de 44 caractere par commentaire dans le chat
    case 2: mvwprintw(chatwin,3,1,"vous pouver vous deplacer"); mvwprintw(chatwin,5,1,"avec les fleches directionnelles"); break;
    case 3: mvwprintw(chatwin,3,1,"vous etes sur une porte "); break;
    case 6: mvwprintw(chatwin,3,1,"vous etes sur un escalier"); break;
    //case ?: ; break;
  }

  wrefresh(chatwin);

}
