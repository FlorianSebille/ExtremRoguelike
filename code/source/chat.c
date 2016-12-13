/**
 * \file chat.c
 * \brief Programme contenant la fonction qui ecrit dans la fenetre du chat
 * \author SEBILLE Florian
 * \version 1.0.1
 */

#include "total.h"

/**
 * \fn effacer_ligne(WINDOW *chatwin, int ligne_effacer)
 * \brief Fonction qui sert a effacer une ligne d'une fenetre donner en parametre.
 *
 * \param chatwin fenetre ou se situe la ligne a effacer.
 * \param ligne_effacer ligne a effacer.
 */
void effacer_ligne(WINDOW *chatwin, int ligne_effacer){
  int colone;
  int lignemax;
  int colonemax;

  getmaxyx(chatwin,lignemax,colonemax);

  for (colone = 1; colone < colonemax; colone++) {
    mvwprintw(chatwin,ligne_effacer,colone," ");
  }
}

/**
 * \fn effacer_fenetre(WINDOW *chatwin)
 * \brief Fonction qui sert a effacer une fenetre donner en parametre.
 *
 * \param chatwin fenetre a effacer.
 */
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

/**
 * \fn ecrire_chat(WINDOW *chatwin, int position_perso)
 * \brief Fonction qui sert a ecrire dans le chat.
 *
 * \param chatwin fenetre ou se situe la ligne a effacer.
 * \param position_perso permet de choisir ce que l'on ecrit dans le chat.
 */
void ecrire_chat(WINDOW *chatwin, int position_perso){

  int lignemax;
  int colonemax;

  getmaxyx(chatwin,lignemax,colonemax); // optention du nombre de colone et de ligne de la troisieme colone
  effacer_fenetre(chatwin);

  // ecrit dans la fenetre en fonction de la position du perso
  mvwprintw(chatwin,1,1,"Vous etes au niveau %i salle %i",joueur.STAGE,joueur.SALLE);
  switch (position_perso) {
    case 2: mvwprintw(chatwin,3,1,"Vous pouvez vous deplacer"); mvwprintw(chatwin,5,1,"avec les fleches directionnelles"); if(joueur.FOOD < 2){wattron(chatwin, COLOR_PAIR(1)); mvwprintw(chatwin,7,1,"Vous etes affamés !!!"); if(joueur.HP <= 5){mvwprintw(chatwin,9,1,"attention vous saignez beaucoup");}}else if(joueur.HP <= 5){mvwprintw(chatwin,7,1,"attention vous saignez beaucoup");} wattroff(chatwin,COLOR_PAIR(1)); break;
    case 3: mvwprintw(chatwin,3,1,"Vous etes sur une porte "); break;
    case 6: mvwprintw(chatwin,3,1,"Vous etes sur un escalier"); break;
    case 8: mvwprintw(chatwin,3,1,"Oh nooon, vous êtes tombés dans ");mvwprintw(chatwin,4,1,"un piège !");break;
    //case ?: ; break;
  }
  noecho();
  wrefresh(chatwin);

}
