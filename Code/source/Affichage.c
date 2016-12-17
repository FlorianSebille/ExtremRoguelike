/**
 * \file Affichage.c
 * \brief Fichier contenant les affichages des différentes fenêtres
 * \author LARDY Anthony
 * \author SEBILLE Florian
 * \version 1.0.1
 */

#include "total.h"

/**
  * \brief Affichage de la fenêtre contenant les statistiques et les commandes
  * \fn void Win_Stat(WINDOW *fenetre, int widthF)
  * \param fenetre Fenêtre où les différents éléments(Statistiques/Commandes) sont affichés
  * \param widthF Nécessaire pour aligner à droite les statistiques
  */

void Win_Stat(WINDOW *fenetre, int widthF){
	int n;
	effacer_fenetre(fenetre);

	wattron(fenetre, A_BOLD | COLOR_PAIR(1));
	mvwprintw(fenetre,2,2, "NOM");
	n = strlen(joueur.nom);
	mvwprintw(fenetre,2,widthF-1-n,"%s", joueur.nom);     /* affichage du nom du joueur. */

	mvwprintw(fenetre,3,2,"ETAGE");
	n = log10(joueur.STAGE) + 1;
	mvwprintw(fenetre,3,widthF-1-n,"%i", joueur.STAGE);		/* affichage de l'étage du joueur. */
	wattroff(fenetre, A_BOLD | COLOR_PAIR(1));

	wattron(fenetre, A_BOLD | COLOR_PAIR(2));
	mvwprintw(fenetre,5,2, "STATS:");
	wattroff(fenetre, A_BOLD | COLOR_PAIR(2));

	mvwprintw(fenetre,6,4,"NIVEAU");
	n = log10(joueur.LEVEL) + 1;
	wattron(fenetre, A_BOLD | COLOR_PAIR(2));
	mvwprintw(fenetre,6,widthF-1-n,"%i", joueur.LEVEL);		/* affichage du niveau du joueur. */
	wattroff(fenetre, A_BOLD | COLOR_PAIR(2));

	if(joueur.EXP == 0){
		mvwprintw(fenetre,7,widthF-2,"0");
	}
	mvwprintw(fenetre,7,4,"EXP");
	n = log10(joueur.EXP) + 1;
	wattron(fenetre, A_BOLD | COLOR_PAIR(2));
	mvwprintw(fenetre,7,widthF-1-n,"%i", joueur.EXP);		/* affichage de l'expérience du joueur. */
	wattroff(fenetre, A_BOLD | COLOR_PAIR(2));

	mvwprintw(fenetre,8,4,"HP");
	n = log10(joueur.HP) + 1;
	if(joueur.HP <= 5){
		wattron(fenetre, A_BOLD | COLOR_PAIR(1));
	}else wattron(fenetre, A_BOLD | COLOR_PAIR(2));
	if(joueur.HP == 0){
		mvwprintw(fenetre,8,widthF-2,"0");
	}else mvwprintw(fenetre,8,widthF-1-n,"%i", joueur.HP);		/* affichage de la vie du joueur. */
	if(joueur.HP <= 5){
		wattroff(fenetre, A_BOLD | COLOR_PAIR(1));
	}else wattroff(fenetre, A_BOLD | COLOR_PAIR(2));

	mvwprintw(fenetre,9,4,"ATT");
	n = log10(joueur.ATT) + 1;
	wattron(fenetre, A_BOLD | COLOR_PAIR(2));
	mvwprintw(fenetre,9,widthF-1-n,"%i", joueur.ATT);		/* affichage de l'attaque du joueur. */
	wattroff(fenetre, A_BOLD | COLOR_PAIR(2));

	mvwprintw(fenetre,10,4,"DEF");
	n = log10(joueur.DEF) + 1;
	wattron(fenetre, A_BOLD | COLOR_PAIR(2));
	mvwprintw(fenetre,10,widthF-1-n,"%i", joueur.DEF);		/* affichage de la défense du joueur. */
	wattroff(fenetre, A_BOLD | COLOR_PAIR(2));

	mvwprintw(fenetre,11,4,"FAIM");
	n = log10(joueur.FOOD) +1;
	if(joueur.FOOD <= 5){
		wattron(fenetre, A_BOLD | COLOR_PAIR(1));
	}else wattron(fenetre, A_BOLD | COLOR_PAIR(2));
	if(joueur.FOOD == 0){
		mvwprintw(fenetre,11,widthF-2,"0");
	}else mvwprintw(fenetre,11,widthF-1-n,"%i", joueur.FOOD);		/* affichage de l'état de faim du joueur. */
	if(joueur.FOOD <= 5){
		wattroff(fenetre, A_BOLD | COLOR_PAIR(1));
	}else wattroff(fenetre, A_BOLD | COLOR_PAIR(2));

	/*if(joueur.addcle == 1){
		wattron(fenetre, A_BOLD | COLOR_PAIR(1));
		mvwprintw(fenetre,13,2,"KEY");					 affichage de si le joueur possède la clé.
		//wattroff(fenetre, A_BOLD | COLOR_PAIR(1));
	}*/

	wattron(fenetre, A_BOLD | COLOR_PAIR(2));
	mvwprintw(fenetre,13,2,"LEGENDE: ");
	wattroff(fenetre, A_BOLD | COLOR_PAIR(2));

	mvwprintw(fenetre,14,4,"JOUEUR");
	n = strlen("f");
	wattron(fenetre, A_BOLD | COLOR_PAIR(10));
	mvwprintw(fenetre,14,widthF-1-n,"@");		/* affichage du symbole de la nourriture. */
	wattroff(fenetre, A_BOLD | COLOR_PAIR(10));

	mvwprintw(fenetre,15,4,"NOURRITURE");
	n = strlen("f");
	wattron(fenetre, A_BOLD | COLOR_PAIR(1));
	mvwprintw(fenetre,15,widthF-1-n,"f");		/* affichage du symbole de la nourriture. */
	wattroff(fenetre, A_BOLD | COLOR_PAIR(1));

	if(joueur.addcle == 0){
		wattron(fenetre, A_BOLD | COLOR_PAIR(1));
	}else wattron(fenetre, A_BOLD | COLOR_PAIR(2));
	mvwprintw(fenetre,16,4,"CLE");
	if(joueur.addcle == 0){
		wattroff(fenetre, A_BOLD | COLOR_PAIR(1));
	}else wattroff(fenetre, A_BOLD | COLOR_PAIR(2));
	n = strlen("K");
	wattron(fenetre, A_BOLD | COLOR_PAIR(1));
	mvwprintw(fenetre,16,widthF-1-n,"K");		/* affichage du symbole de la clé. */
	wattroff(fenetre, A_BOLD | COLOR_PAIR(1));

	mvwprintw(fenetre,17,4,"MEDIKIT");
	n = strlen("M");
	wattron(fenetre, A_BOLD | COLOR_PAIR(1));
	mvwprintw(fenetre,17,widthF-1-n,"M");		/* affichage du symbole du medikit. */
	wattroff(fenetre, A_BOLD | COLOR_PAIR(1));

	mvwprintw(fenetre,18,4,"ESCALIER");
	n = strlen("f");
	wattron(fenetre, A_BOLD | COLOR_PAIR(11));
	mvwaddch(fenetre, 18, widthF-1-n, ACS_PI);		/* affichage du symbole pour changer de STAGE. */
	wattroff(fenetre, A_BOLD | COLOR_PAIR(11));

	mvwprintw(fenetre,19,4,"ARRIVE");
	n = strlen("f");
	wattron(fenetre, A_BOLD | COLOR_PAIR(2));
	mvwaddch(fenetre, 19, widthF-1-n, ACS_CKBOARD);		/* affichage du symbole de la porte finale. */
	wattroff(fenetre, A_BOLD | COLOR_PAIR(2));

	mvwprintw(fenetre,20,4,"MONSTRES");
	n = strlen("f");
	wattron(fenetre, A_BOLD | COLOR_PAIR(1));
	mvwprintw(fenetre, 20, widthF-1-n, "T");		/* affichage du symbole des Monstres. */
	wattroff(fenetre, A_BOLD | COLOR_PAIR(1));

	wattron(fenetre, A_BOLD | COLOR_PAIR(2));
	mvwprintw(fenetre,22,2,"COMMANDE: ");
	wattroff(fenetre, A_BOLD | COLOR_PAIR(2));

	mvwprintw(fenetre,23,4,"QUITTER");
	n = strlen("Q");
	mvwprintw(fenetre,23,widthF-1-n,"Q");		/* affichage de la touche pour quitter. */

	mvwprintw(fenetre,24,4,"SAUVEGARDER");
	n = strlen("S");
	mvwprintw(fenetre,24,widthF-1-n,"S");		/* affichage de la touche pour sauvegarder. */

	wattron(fenetre, A_BOLD | COLOR_PAIR(2));
	mvwprintw(fenetre,25,2,"DEPLACEMENT:");
	wattroff(fenetre, A_BOLD | COLOR_PAIR(2));

	n = strlen("FLECHE   HAUT");
	mvwprintw(fenetre,26,widthF-1-n,"FLECHE   HAUT");		/* affichage de la touche pour monter. */
	mvwprintw(fenetre,26,4,"HAUT");

	n = strlen("FLECHE    BAS");
	mvwprintw(fenetre,27,widthF-1-n,"FLECHE    BAS");		/* affichage de la touche pour descendre. */
	mvwprintw(fenetre,27,4,"BAS");

	n = strlen("FLECHE DROITE");
	mvwprintw(fenetre,28,widthF-1-n,"FLECHE DROITE");		/* affichage de la touche pour aller à droite. */
	mvwprintw(fenetre,28,4,"DROITE");

	n = strlen("FLECHE GAUCHE");
	mvwprintw(fenetre,29,widthF-1-n,"FLECHE GAUCHE");		/* affichage de la touche pour aller à gauche. */
	mvwprintw(fenetre,29,4,"GAUCHE");

	wrefresh(fenetre);
}


/**
 * \fn effacer_ligne(WINDOW *chatwin, int ligne_effacer)
 * \brief Fonction qui sert à effacer une ligne d'une fenêtre donnée en paramètre.
 *
 * \param chatwin fenêtre où se situe la ligne à effacer.
 * \param ligne_effacer ligne à effacer.
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
 * \brief Fonction qui sert à effacer une fenêtre donnée en paramètre.
 *
 * \param chatwin fenêtre à effacer.
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
 * \brief Fonction qui sert à écrire dans le chat.
 *
 * \param chatwin fenêtre où se situe la ligne à effacer.
 * \param position_perso permet de choisir ce que l'on écrit dans le chat.
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

/**
 * \fn void affichage(WINDOW *fenetre)
 * \brief Fonction d'affichage de la map de jeu.
 *
 * \param fenetre contenant la map.
 */
void affichage(WINDOW *fenetre){

  int i,j;

  for(i = 1; i < x-1; i++){    /* Parcour de la matrice pour afficher dans la fenetre les diferents elements. */
    for(j = 1; j < y-1; j++){

      if(MAP[i][j].lieu == vide){   /* affichage du vide en dehors des salle et des couloirs. */
        mvwprintw(fenetre,i,j," ");

      }else if(MAP[i][j].lieu == couloir){ /* affichage des couloirs qui relie les différentes salles. */
        wattron(fenetre, COLOR_PAIR(6));
        mvwprintw(fenetre,i,j," ");
        wattroff(fenetre, COLOR_PAIR(6));

      }else if(MAP[i][j].lieu == porte){    /* affichage des portes qui se situe a l'entrer des couloirs. */
        wattron(fenetre, COLOR_PAIR(6));
        mvwprintw(fenetre,i,j," ");
        wattroff(fenetre, COLOR_PAIR(6));

      }else if(MAP[i][j].lieu == uplevel){  /* affichage des escaliers qui font la liaisons entre les etages. */
        wattron(fenetre, COLOR_PAIR(5));
        mvwaddch(fenetre, i, j, ACS_PI);
        wattroff(fenetre, COLOR_PAIR(5));

      }else if(MAP[i][j].lieu == sol){      /* affichage du sol des salles. */
        wattron(fenetre, COLOR_PAIR(4));
        mvwprintw(fenetre,i,j," ");
        wattroff(fenetre, COLOR_PAIR(4));

      }else if(MAP[i][j].lieu == mur){      /* affichage des murs qui délimittes les salles. */
        wattron(fenetre, COLOR_PAIR(4));
        mvwaddch(fenetre, i, j, ACS_CKBOARD);
        wattroff(fenetre, COLOR_PAIR(4));

      }else if(MAP[i][j].lieu == piege && cheat == 1){    /* afficge des pièges qui si on marche dessus provoque la mort. */
        wattron(fenetre, COLOR_PAIR(5));
        mvwprintw(fenetre, i, j, "&");
        wattroff(fenetre, COLOR_PAIR(4));

      }else if(MAP[i][j].lieu == piege && cheat == 0){    /* afficge des pièges qui si on marche dessus provoque la mort. */
        wattron(fenetre, COLOR_PAIR(5));
        mvwprintw(fenetre, i, j, " ");
        wattroff(fenetre, COLOR_PAIR(4));

      }else if(MAP[i][j].lieu == personnage){   /* affichage du personnage. */
        wattron(fenetre, COLOR_PAIR(3));
      	mvwprintw(fenetre,i,j,"@");
        wattroff(fenetre, COLOR_PAIR(3));

      }else if(MAP[i][j].lieu == arriver){      /* affichage de l'arriver. */
        wattron(fenetre, COLOR_PAIR(8));
      	mvwaddch(fenetre, i, j, ACS_CKBOARD);
        wattroff(fenetre, COLOR_PAIR(8));

      }else if(MAP[i][j].lieu == food){       /* affichage de la nouriture. */
        wattron(fenetre, COLOR_PAIR(7));
      	mvwprintw(fenetre, i, j,"f");
        wattroff(fenetre, COLOR_PAIR(7));

      }else if(MAP[i][j].lieu == cle){    /* affichage de la clé. */
        wattron(fenetre, COLOR_PAIR(7));
        mvwprintw(fenetre,i,j,"K");
        wattroff(fenetre, COLOR_PAIR(7));

      }else if(MAP[i][j].lieu == mechant && monstre.HP > 0){ /* affichage des différents monstres. */
        wattron(fenetre, COLOR_PAIR(7));
        mvwprintw(fenetre,i,j,"T");

      }else if(MAP[i][j].lieu == medikit){    /* affichage des medikits. */
        wattron(fenetre, COLOR_PAIR(7));
      	mvwprintw(fenetre, i, j,"M");
        wattroff(fenetre, COLOR_PAIR(7));
      }
    }
  }
  wrefresh(fenetre); /* rafrechit la fenetre contenant la map. */
}
