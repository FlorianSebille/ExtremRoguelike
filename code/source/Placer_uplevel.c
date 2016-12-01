#include "total.h"

int Placer_uplevel(t_cellule MAP [x] [y], WINDOW *fenetre){

    int i,max_i,j,max_j,taille_salle;
    taille_salle = 0;
    getmaxyx(fenetre,max_i,max_j);

  for(i = 1; i < max_i -1; i++){
  	for(j = 1; j < max_j -1; j++){
    	if(MAP[i][j].num_salle == nombre_salle-1){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
				}
  		}
		}
  }

  int pos_uplevel = aleat(0,taille_salle);
  taille_salle = 0;

  for(i = 1; i < max_i -1; i++){
  	for(j = 1; j < max_j -1; j++){
    	if(MAP[i][j].num_salle == nombre_salle-1){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
          if(taille_salle == pos_uplevel){
            MAP[i][j].lieu=uplevel;
            return 1;
          }
				}
  		}
		}
  }
	return 0;
}
