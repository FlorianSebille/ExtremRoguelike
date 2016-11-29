#include "total.h"

int Placer_perso(t_cellule MAP [x] [y], WINDOW *fenetre){
	
	int i,max_i,j,max_j;
  	getmaxyx(fenetre,max_i,max_j);

  	for(i = 1; i < max_i -1; i++){
    		for(j = 1; j < max_j -1; j++){
    			if(MAP[i][j].num_salle == 0){
    				if(MAP[i][j].lieu == sol){
    					joueur.positionx=i;
    					joueur.positiony=j;
    					MAP[i][j].lieu=personnage;
                        return 1;
    				}
    			}    		
    		}

    }
    return 0;
}
