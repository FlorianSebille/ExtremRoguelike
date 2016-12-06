#include "total.h"

int test_depl(int c){

 	switch(c){
 		case KEY_UP:	if(MAP[joueur.coordo_x-1][joueur.coordo_y].lieu == mur /*|| MAP[temp_joueur.coordo_x-1][temp_joueur.coordo_y].lieu == vide*/){
 										return 0;
 									}else{
 										return 1;
 									}
 	  case KEY_DOWN:	if(MAP[joueur.coordo_x+1][joueur.coordo_y].lieu == mur /*|| MAP[temp_joueur.coordo_x+1][temp_joueur.coordo_y].lieu == vide*/){
 											return 0;
 										}else{
 											return 1;
 										}
 		case KEY_LEFT:	if(MAP[joueur.coordo_x][joueur.coordo_y-1].lieu == mur /*|| MAP[temp_joueur.coordo_x][temp_joueur.coordo_y-1].lieu == vide*/){
 											return 0;
 										}else{
 											return 1;
 										}
 		case KEY_RIGHT:	if(MAP[joueur.coordo_x][joueur.coordo_y+1].lieu == mur /*|| MAP[temp_joueur.coordo_x-1][temp_joueur.coordo_y+1].lieu == vide*/){
 											return 0;
 										}else{
 											return 1;
     							  }
 	}
 	return 0;
}

int Depl_perso(WINDOW *fenetre){

	cbreak();
	keypad(stdscr,TRUE);
 	timeout(0);

 	int c;

	c = getch();


	if(c!=ERR){
		switch(c){
			case KEY_UP:	if(test_depl(c)){
											ecrire_chat(fenetre, MAP[joueur.coordo_x-1][joueur.coordo_y].lieu);
											MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
											joueur.etat_avant = MAP[joueur.coordo_x-1][joueur.coordo_y].lieu;
											MAP[joueur.coordo_x-1][joueur.coordo_y].lieu = personnage;
											joueur.coordo_x--;
                      deplacement = 5;
                      nb_deplacement++;
										}
										break;
			case KEY_DOWN:	if(test_depl(c)){
												ecrire_chat(fenetre, MAP[joueur.coordo_x+1][joueur.coordo_y].lieu);
												MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
												joueur.etat_avant = MAP[joueur.coordo_x+1][joueur.coordo_y].lieu;
												MAP[joueur.coordo_x+1][joueur.coordo_y].lieu = personnage;
												joueur.coordo_x++;
                        deplacement = 2;
                        nb_deplacement++;
											}
											break;
			case KEY_LEFT:	if(test_depl(c)){
												ecrire_chat(fenetre, MAP[joueur.coordo_x][joueur.coordo_y-1].lieu);
												MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
												joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y-1].lieu;
												MAP[joueur.coordo_x][joueur.coordo_y-1].lieu = personnage;
												joueur.coordo_y--;
                        deplacement = 1;
                        nb_deplacement++;
											}
											break;
			case KEY_RIGHT: if(test_depl(c)){
												ecrire_chat(fenetre, MAP[joueur.coordo_x][joueur.coordo_y+1].lieu);
												MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
												joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y+1].lieu;
												MAP[joueur.coordo_x][joueur.coordo_y+1].lieu = personnage;
												joueur.coordo_y++;
                        deplacement = 3;
                        nb_deplacement++;
											}
											break;
		}
	}

/* KEY PART */

  if(joueur.etat_avant == cle){ // le joueur recupere la clé
    joueur.addcle = 1;
    joueur.etat_avant = sol;
  }

  if(joueur.etat_avant == arriver && joueur.addcle == 1){     // le joueur est a l'arriver avec la clé

  }

/* TRAP PART */

  if(joueur.etat_avant == piege){
    ecrire_chat(fenetre,8);
    mort = 1;
  }
  
/* FOOD PART */

  if(nb_deplacement == 7){ //si le joueur effecue 5 déplacements alors il perd 1 dans sa barre de food
    joueur.FOOD--;
    nb_deplacement = 0;
  }

  if(joueur.etat_avant == food){ //si le joueur marche sur un item food, il récupère ce qu'il a perdu
    nb_deplacement = 0;
    joueur.FOOD = 9;
    joueur.etat_avant = sol;
  }

	return c;
}
