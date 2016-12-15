/**
 * \file Charger_Sauvegarde.c
 * \brief Fichier contenant la fontion pour le combat
 * \author LARDY Anthony
 * \version 1.0.1
 */

#include "total.h"

/**
  * \brief Gère le combat entre le joueur et le monstre
  * \fn void combat()
  */
void combat(){
	if(MAP[monstre.coordo_x][monstre.coordo_y+1].lieu == personnage){
		joueur.HP = 0;
	}else if(MAP[monstre.coordo_x][monstre.coordo_y-1].lieu == personnage){
		joueur.HP = 0;
	}else if(MAP[monstre.coordo_x+1][monstre.coordo_y-1].lieu == personnage){
		joueur.HP = 0;
	}else if(MAP[monstre.coordo_x+1][monstre.coordo_y].lieu == personnage){
		joueur.HP = 0;
	}else if(MAP[monstre.coordo_x+1][monstre.coordo_y+1].lieu == personnage){
		joueur.HP = 0;
	}else if(MAP[monstre.coordo_x-1][monstre.coordo_y-1].lieu == personnage){
		joueur.HP = 0;
	}else if(MAP[monstre.coordo_x-1][monstre.coordo_y].lieu == personnage){
		joueur.HP = 0;
	}else if(MAP[monstre.coordo_x-1][monstre.coordo_y+1].lieu == personnage){
		joueur.HP = 0;
	}
}
