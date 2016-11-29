#include "total.h"


void ecrire_chat(WINDOW *chatwin, int *ligne, int position_perso){  // fonction qui ecrit dans la fenetre chat

  int lignemax;
  int colonemax;

  int heightT = 31;    /* Dimensions et Position de la 3ème fenêtre */
  int widthT = 36;
  int startyT = 2 ;
  int startxT = 134 ;

  getmaxyx(chatwin,lignemax,colonemax); // optention du nombre de colone et de ligne de la troisieme colone

  if(*ligne >= lignemax-1){  // si on est plus bas que la derniere ligne de la fenetre

    destroy_win(chatwin);
    chatwin = create_newwin(heightT,widthT,startyT,startxT,"Chat");
    *ligne = 1;

  }
  // ecrit dans la fenetre en fonction de la position du perso
  mvwprintw(chatwin,*ligne,1,"vous etes au niveau %i dans la salle %i",joueur.STAGE,joueur.SALLE);
  *ligne = *ligne + 2;
  switch (position_perso) { // pas plus de 44 caractere par commentaire dans le chat
    case 2: mvwprintw(chatwin,*ligne,1,"vous pouver vous deplacer"); *ligne++; mvwprintw(chatwin,*ligne,1,"avec les fleches directionnelles"); break;
    case 3: mvwprintw(chatwin,*ligne,1,"vous etes sur une porte "); *ligne++; mvwprintw(chatwin,*ligne,1,"voulez vous allez dans la salle suivante"); *ligne++; mvwprintw(chatwin,*ligne,10,"oui: appuier sur entrer"); *ligne++; mvwprintw(chatwin,*ligne,20,"non: appuier sur supprimer"); break;
    case 6: mvwprintw(chatwin,*ligne,1,"vous etes sur un escalier"); *ligne++; mvwprintw(chatwin,*ligne,1,"voulez vous allez dans le stage suivant"); *ligne++; mvwprintw(chatwin,*ligne,10,"oui: appuier sur entrer"); *ligne++; mvwprintw(chatwin,*ligne,20,"non: appuier sur supprimer"); break;
    //case ?: ; break;
  }
  /*if(position_perso == 3){
    char choix = getch();
    if(choix == 'ENTER'){

    }
  }*/
  *ligne = *ligne + 2;
  wrefresh(chatwin);

}
