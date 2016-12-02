#include "total.h"

int test_depl(t_cellule MAP [x] [y], int c,t_joueur joueur){

 	t_joueur temp_joueur;
 	temp_joueur = joueur;
 	switch(c){
 		case KEY_UP:	if(MAP[temp_joueur.coordo_x-1][temp_joueur.coordo_y].lieu == mur || MAP[temp_joueur.coordo_x-1][temp_joueur.coordo_y].lieu == vide){
 										return 0;
 									}else{
 										return 1;
 									}
 	  case KEY_DOWN:	if(MAP[temp_joueur.coordo_x+1][temp_joueur.coordo_y].lieu == mur || MAP[temp_joueur.coordo_x+1][temp_joueur.coordo_y].lieu == vide){
 											return 0;
 										}else{
 											return 1;
 										}
 		case KEY_LEFT:	if(MAP[temp_joueur.coordo_x][temp_joueur.coordo_y-1].lieu == mur || MAP[temp_joueur.coordo_x][temp_joueur.coordo_y-1].lieu == vide){
 											return 0;
 										}else{
 											return 1;
 										}
 		case KEY_RIGHT:	if(MAP[temp_joueur.coordo_x][temp_joueur.coordo_y+1].lieu == mur || MAP[temp_joueur.coordo_x-1][temp_joueur.coordo_y+1].lieu == vide){
 											return 0;
 										}else{
 											return 1;
     							  }
 	}
 	return 0;
}

int Depl_perso(t_cellule MAP [x] [y],t_joueur *joueur, WINDOW *fenetre){

	cbreak();
	keypad(stdscr,TRUE);
 	timeout(0);

 	int c;
	t_joueur temp_joueur;

 	temp_joueur = *joueur;

	c = getch();
	if(c!=ERR){
		switch(c){
			case KEY_UP:	if(test_depl(MAP, c, temp_joueur)){
											ecrire_chat(fenetre, MAP[temp_joueur.coordo_x-1][temp_joueur.coordo_y].lieu);
											MAP[temp_joueur.coordo_x][temp_joueur.coordo_y].lieu = temp_joueur.etat_avant;
											temp_joueur.etat_avant = MAP[temp_joueur.coordo_x-1][temp_joueur.coordo_y].lieu;
											MAP[temp_joueur.coordo_x-1][temp_joueur.coordo_y].lieu = personnage;
											temp_joueur.coordo_x--;
                      deplacement = 5;
										}
										break;
			case KEY_DOWN:	if(test_depl(MAP, c, temp_joueur)){
												ecrire_chat(fenetre, MAP[temp_joueur.coordo_x+1][temp_joueur.coordo_y].lieu);
												MAP[temp_joueur.coordo_x][temp_joueur.coordo_y].lieu = temp_joueur.etat_avant;
												temp_joueur.etat_avant = MAP[temp_joueur.coordo_x+1][temp_joueur.coordo_y].lieu;
												MAP[temp_joueur.coordo_x+1][temp_joueur.coordo_y].lieu = personnage;
												temp_joueur.coordo_x++;
                        deplacement = 2;
											}
											break;
			case KEY_LEFT:	if(test_depl(MAP, c, temp_joueur)){
												ecrire_chat(fenetre, MAP[temp_joueur.coordo_x][temp_joueur.coordo_y-1].lieu);
												MAP[temp_joueur.coordo_x][temp_joueur.coordo_y].lieu = temp_joueur.etat_avant;
												temp_joueur.etat_avant = MAP[temp_joueur.coordo_x][temp_joueur.coordo_y-1].lieu;
												MAP[temp_joueur.coordo_x][temp_joueur.coordo_y-1].lieu = personnage;
												temp_joueur.coordo_y--;
                        deplacement = 1;
											}
											break;
			case KEY_RIGHT: if(test_depl(MAP, c, temp_joueur)){
												ecrire_chat(fenetre, MAP[temp_joueur.coordo_x][temp_joueur.coordo_y+1].lieu);
												MAP[temp_joueur.coordo_x][temp_joueur.coordo_y].lieu = temp_joueur.etat_avant;
												temp_joueur.etat_avant = MAP[temp_joueur.coordo_x][temp_joueur.coordo_y+1].lieu;
												MAP[temp_joueur.coordo_x][temp_joueur.coordo_y+1].lieu = personnage;
												temp_joueur.coordo_y++;
                        deplacement = 3;
											}
											break;
		}
	}
  if(temp_joueur.etat_avant == cle){ // le joueur recupere la clé
    temp_joueur.addcle = 1;
    temp_joueur.etat_avant = sol;
  }
  if(temp_joueur.etat_avant == arriver && temp_joueur.addcle == 1){// le joueur est a l'arriver avec la clé

  }
	*joueur = temp_joueur;
	return c;
}
