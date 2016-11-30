#include "total.h"

int Placer_perso(t_cellule MAP [x] [y], WINDOW *fenetre){

  int i,max_i,j,max_j,taille_salle;
  taille_salle = 0;
  getmaxyx(fenetre,max_i,max_j);

  for(i = 1; i < max_i -1; i++){
    for(j = 1; j < max_j -1; j++){
      if(MAP[i][j].num_salle == 0){
      	if(MAP[i][j].lieu == sol){
          taille_salle++;
        }
      }
    }
  }

  int pos_perso = aleat(0,taille_salle);
  taille_salle = 0;

  for(i = 1; i < max_i -1; i++){
  	for(j = 1; j < max_j -1; j++){
    	if(MAP[i][j].num_salle == 0){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
          if(taille_salle == pos_perso){
            joueur.coordo_x=i;
            joueur.coordo_y=j;
            joueur.etat_avant = 2;
            joueur.STAGE = 1;
            joueur.SALLE = 1;
            MAP[i][j].lieu=personnage;
            return 1;
          }
				}
  		}
		}
  }
	return 0;
}
