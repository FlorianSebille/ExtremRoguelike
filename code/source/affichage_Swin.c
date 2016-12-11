#include "total.h"

/**
 * \fn void affichage(WINDOW *fenetre)
 * \brief Fonction d'affichage de la map de jeu.
 *
 * \param fenetre contenant la map.
 */
void affichage(WINDOW *fenetre){

  int i,max_i,j,max_j;
  getmaxyx(fenetre,max_i,max_j);

  for(i = 1; i < max_i -1; i++){    /*!< Parcour de la matrice pour afficher dans la fenetre les diferents elements. */
    for(j = 1; j < max_j -1; j++){

      if(MAP[i][j].lieu == vide){   /*!< affichage du vide en dehors des salle et des couloirs. */
        mvwprintw(fenetre,i,j," ");

      }else if(MAP[i][j].lieu == couloir){ /*!< affichage des couloirs qui relie les différentes salles. */
        wattron(fenetre, COLOR_PAIR(6));
        mvwprintw(fenetre,i,j," ");
        wattroff(fenetre, COLOR_PAIR(6));

      }else if(MAP[i][j].lieu == porte){    /*!< affichage des portes qui se situe a l'entrer des couloirs. */
        wattron(fenetre, COLOR_PAIR(6));
        mvwprintw(fenetre,i,j," ");
        wattroff(fenetre, COLOR_PAIR(6));

      }else if(MAP[i][j].lieu == uplevel){  /*!< affichage des escaliers qui font la liaisaons entre les etages. */
        wattron(fenetre, COLOR_PAIR(5));
        mvwaddch(fenetre, i, j, ACS_PI);
        wattroff(fenetre, COLOR_PAIR(5));

      }else if(MAP[i][j].lieu == sol){      /*!< affichage du sol des salles. */
        wattron(fenetre, COLOR_PAIR(4));
        mvwprintw(fenetre,i,j," ");
        wattroff(fenetre, COLOR_PAIR(4));

      }else if(MAP[i][j].lieu == mur){      /*!< affichage des murs qui délimittes les salles. */
        wattron(fenetre, COLOR_PAIR(4));
        mvwaddch(fenetre, i, j, ACS_CKBOARD);
        wattroff(fenetre, COLOR_PAIR(4));

      }else if(MAP[i][j].lieu == piege){    /*!< afficge des pièges qui si on marche dessus provoque la mort. */
        wattron(fenetre, COLOR_PAIR(5));
        mvwprintw(fenetre, i, j, "&");
        wattroff(fenetre, COLOR_PAIR(4));

      }else if(MAP[i][j].lieu == personnage){   /*!< affichage du personnage. */
        wattron(fenetre, COLOR_PAIR(3));
      	mvwprintw(fenetre,i,j,"@");
        wattroff(fenetre, COLOR_PAIR(3));

      }else if(MAP[i][j].lieu == arriver){      /*!< affichage de l'arriver. */
        wattron(fenetre, COLOR_PAIR(8));
      	mvwaddch(fenetre, i, j, ACS_CKBOARD);
        wattroff(fenetre, COLOR_PAIR(8));

      }else if(MAP[i][j].lieu == food){       /*!< affichage de la nouriture. */
        wattron(fenetre, COLOR_PAIR(7));
      	mvwprintw(fenetre, i, j,"f");
        wattroff(fenetre, COLOR_PAIR(7));

      }else if(MAP[i][j].lieu == cle){    /*!< affichage de la clé. */
        wattron(fenetre, COLOR_PAIR(7));
        mvwprintw(fenetre,i,j,"K");
        wattroff(fenetre, COLOR_PAIR(7));

      }else if(MAP[i][j].lieu == mechant && monstre.HP > 0){ /*!< affichage des différents monstres. */
        wattron(fenetre, COLOR_PAIR(7));
        mvwprintw(fenetre,i,j,"T");

      }else if(MAP[i][j].lieu == medikit){    /*!< affichage des medikits. */
        wattron(fenetre, COLOR_PAIR(7));
      	mvwprintw(fenetre, i, j,"M");
        wattroff(fenetre, COLOR_PAIR(7));
      }
    }
  }
  wrefresh(fenetre); /*!< rafrechit la fenetre contenant la map. */
}
