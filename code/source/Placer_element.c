
#include "total.h"

int Placer_perso(WINDOW *fenetre){

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
            MAP[i][j].lieu=personnage;
            return 1;
          }
				}
  		}
		}
  }
	return 0;
}

int Placer_uplevel(WINDOW *fenetre){

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
            if(joueur.STAGE == 5){
              MAP[i][j].lieu=arriver;
            }else{
              MAP[i][j].lieu=uplevel;
              return 1;
            }
          }
				}
  		}
		}
  }
	return 0;
}

int Placer_cle(WINDOW *fenetre){

    int i,max_i,j,max_j,salle,taille_salle;
    salle = aleat(1,nombre_salle-2);
    taille_salle = 0;
    getmaxyx(fenetre,max_i,max_j);

  for(i = 1; i < max_i -1; i++){
  	for(j = 1; j < max_j -1; j++){
    	if(MAP[i][j].num_salle == salle){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
				}
  		}
		}
  }

  int pos_cle = aleat(0,taille_salle);
  taille_salle = 0;

  for(i = 1; i < max_i -1; i++){
  	for(j = 1; j < max_j -1; j++){
    	if(MAP[i][j].num_salle == salle){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
          if(taille_salle == pos_cle && joueur.addcle == 0){
              MAP[i][j].lieu=cle;
              return 1;
          }
				}
  		}
		}
  }
	return 0;
}
