/**
 * \file monstre.c
 * \brief Programme regroupant les fonctions pour le déplacement du monstre.
 * \author LARDY Anthony
 * \version 1.0.1
 */

#include "total.h"

/**
  * \brief Fonction qui fait déplacer le monstre aléatoirement
  * \fn void depl_monstre()
  */

void depl_monstre(){
	int futury,futurx;
	do{
		int	Depl_aleatoire = aleat(0,5);		/*!< Choisit de façon aléatoire le déplacement du monstre */
		switch(Depl_aleatoire){
			case 1:futurx = monstre.coordo_x-1; futury = monstre.coordo_y;break;
			case 2:futurx = monstre.coordo_x+1; futury = monstre.coordo_y;break;
			case 3:futurx = monstre.coordo_x; futury = monstre.coordo_y-1;break;
			case 4:futurx = monstre.coordo_x; futury = monstre.coordo_y+1;break;
			default:futurx = monstre.coordo_x; futury = monstre.coordo_y; break;
		}
	}while(MAP[futurx][futury].lieu != sol);
	MAP[monstre.coordo_x][monstre.coordo_y].lieu = sol;
	monstre.coordo_y = futury;
	monstre.coordo_x = futurx;
	MAP[monstre.coordo_x][monstre.coordo_y].lieu = mechant;
}
