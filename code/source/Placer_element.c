/**
 * \file Placer_element.c
 * \brief Place tous les éléments du la carte.
 * \author LARDY Anthony
 * \author TROTTIER Arthur
 * \author SEBILLE Florian
 * \version 1.0.1
 */

#include "total.h"

/**
  * \brief Place le personnage
  * \fn int Placer_perso()
  */
int Placer_perso(){

  int i,j,taille_salle;
  taille_salle = 0;

  for(i = 1; i < x; i++){
    for(j = 1; j < y; j++){
      if(MAP[i][j].num_salle == 0){
      	if(MAP[i][j].lieu == sol){
          taille_salle++;
        }
      }
    }
  }

  int pos_perso = aleat(0,taille_salle);
  taille_salle = 0;

  for(i = 1; i < x; i++){
  	for(j = 1; j < y; j++){
    	if(MAP[i][j].num_salle == 0){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
          if(taille_salle == pos_perso){
            joueur.coordo_x=i;
            joueur.coordo_y=j;
            joueur.etat_avant = 2;
            MAP[i][j].lieu=personnage;
          }
				}
  		}
		}
  }
  for(i = 1; i < x; i++){ // test pour verifier que le perso est placer sinon on recommence la fonction
    for(j = 1; j < y; j++){
      if(MAP[i][j].num_salle == 0){
        if(MAP[i][j].lieu==personnage){
          return 1;
        }
      }
    }
  }
  Placer_perso();
  return 0;
}

/**
  * \brief Place l'escalier
  * \fn int Placer_uplevel()
  */
int Placer_uplevel(){

    int i,j,taille_salle;
    taille_salle = 0;

  for(i = 1; i < x; i++){
  	for(j = 1; j < y; j++){
    	if(MAP[i][j].num_salle == nombre_salle-1){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
				}
  		}
		}
  }

  int pos_uplevel = aleat(0,taille_salle);
  taille_salle = 0;

  for(i = 1; i < x; i++){
  	for(j = 1; j < y; j++){
    	if(MAP[i][j].num_salle == nombre_salle-1){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
          if(taille_salle == pos_uplevel){
            if(joueur.STAGE == 5){
              if(MAP[i][j+1].lieu==porte){
                MAP[i][j-1].lieu=arriver;
              }else if(MAP[i][j-1].lieu==porte){
                MAP[i][j+1].lieu=arriver;
              }else if(MAP[i+1][j].lieu==porte){
                MAP[i-1][j].lieu=arriver;
              }else if(MAP[i-1][j].lieu==porte){
                MAP[i+1][j].lieu=arriver;
              }else MAP[i][j].lieu=arriver;
            }else{
              if(MAP[i][j+1].lieu==porte){
                MAP[i][j-1].lieu=uplevel;
              }else if(MAP[i][j-1].lieu==porte){
                MAP[i][j+1].lieu=uplevel;
              }else if(MAP[i+1][j].lieu==porte){
                MAP[i-1][j].lieu=uplevel;
              }else if(MAP[i-1][j].lieu==porte){
                MAP[i+1][j].lieu=uplevel;
              }else MAP[i][j].lieu=uplevel;
            }
          }
				}
  		}
		}
  }
  for(i = 1; i < x; i++){ // test pour verifier que uplevel ou l'arriver est placer sinon on recommence la fonction
    for(j = 1; j < y; j++){
      if(MAP[i][j].num_salle == nombre_salle-1){
        if(MAP[i][j].lieu==uplevel || MAP[i][j].lieu==arriver){
          return 1;
        }
      }
    }
  }
  Placer_uplevel();
	return 0;
}

/**
  * \brief Place la clé
  * \fn int Placer_cle()
  */
int Placer_cle(){

    int i,j,salle,taille_salle;
    salle = aleat(1,nombre_salle-2);
    taille_salle = 0;

  for(i = 1; i < x; i++){
  	for(j = 1; j < y; j++){
    	if(MAP[i][j].num_salle == salle){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
				}
  		}
		}
  }

  int pos_cle = aleat(0,taille_salle);
  taille_salle = 0;

  for(i = 1; i < x; i++){
  	for(j = 1; j < y; j++){
    	if(MAP[i][j].num_salle == salle){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
          if(taille_salle == pos_cle && joueur.addcle == 0){
            if(MAP[i][j+1].lieu==porte){
              MAP[i][j-1].lieu=cle;
            }else if(MAP[i][j-1].lieu==porte){
              MAP[i][j+1].lieu=cle;
            }else if(MAP[i+1][j].lieu==porte){
              MAP[i-1][j].lieu=cle;
            }else if(MAP[i-1][j].lieu==porte){
              MAP[i+1][j].lieu=cle;
            }else MAP[i][j].lieu=cle;
          }
				}
  		}
		}
  }
  for(i = 1; i < x; i++){ // test pour verifier que la clé est placer sinon on recommence la fonction
    for(j = 1; j < y; j++){
      if(MAP[i][j].num_salle == salle){
        if(MAP[i][j].lieu==cle){
          return 1;
        }
      }
    }
  }
  Placer_cle();
	return 0;
}

/**
  * \brief Place le monstre
  * \fn int Placer_monstre()
  */
int Placer_monstre(){
  int i, j;
  monstre.salle = aleat(0,nombre_salle - 1);
  int x_salle = aleat(0,4);
  int y_salle = aleat(0,9);
  for(i=0;i<x;i++){
    for(j=0;j<y;j++){
      if(MAP[i][j].num_salle == monstre.salle && MAP[i][j].lieu == sol && joueur.STAGE > 1){
        while(MAP[i+x_salle][j+y_salle].lieu != sol){
                x_salle++;
                y_salle++;
        }
        MAP[i+x_salle][j+x_salle].lieu = mechant;
        monstre.coordo_x = i+x_salle;
        monstre.coordo_y = j+x_salle;
        monstre.EXP = 300;
        monstre.ATT = 7;
        monstre.HP = 10;
        monstre.DEF = 4;
        return 1;
      }
    }
  }
  return 0;
}

/**
  * \brief Place le medikit
  * \fn int Placer_medikit()
  */
int Placer_medikit(){

    int i,j,salle,taille_salle;
    salle = aleat(1,nombre_salle-2);
    taille_salle = 0;

  for(i = 1; i < x; i++){
  	for(j = 1; j < y; j++){
    	if(MAP[i][j].num_salle == salle){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
				}
  		}
		}
  }

  int pos_medikit = aleat(0,taille_salle);
  taille_salle = 0;

  for(i = 1; i < x; i++){
  	for(j = 1; j < y; j++){
    	if(MAP[i][j].num_salle == salle){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
          if(taille_salle == pos_medikit){
            if(MAP[i][j+1].lieu==porte){
              MAP[i][j-1].lieu=medikit;
            }else if(MAP[i][j-1].lieu==porte){
              MAP[i][j+1].lieu=medikit;
            }else if(MAP[i+1][j].lieu==porte){
              MAP[i-1][j].lieu=medikit;
            }else if(MAP[i-1][j].lieu==porte){
              MAP[i+1][j].lieu=medikit;
            }else MAP[i][j].lieu=medikit;
          }
				}
  		}
		}
  }
  for(i = 1; i < x; i++){ // test pour verifier que la clé est placer sinon on recommence la fonction
    for(j = 1; j < y; j++){
      if(MAP[i][j].num_salle == salle){
        if(MAP[i][j].lieu==medikit){
          return 1;
        }
      }
    }
  }
  Placer_medikit();
	return 0;
}

/**
  * \brief Place la nourriture
  * \fn int Placer_food()
  */
int Placer_food(){

    int i,j,salle,taille_salle;
    salle = aleat(1,nombre_salle-2);
    taille_salle = 0;

  for(i = 1; i < x; i++){
  	for(j = 1; j < y; j++){
    	if(MAP[i][j].num_salle == salle){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
				}
  		}
		}
  }

  int pos_food = aleat(0,taille_salle);
  taille_salle = 0;

  for(i = 1; i < x; i++){
  	for(j = 1; j < y; j++){
    	if(MAP[i][j].num_salle == salle){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
          if(taille_salle == pos_food){
            if(MAP[i][j+1].lieu==porte){
              MAP[i][j-1].lieu=food;
            }else if(MAP[i][j-1].lieu==porte){
              MAP[i][j+1].lieu=food;
            }else if(MAP[i+1][j].lieu==porte){
              MAP[i-1][j].lieu=food;
            }else if(MAP[i-1][j].lieu==porte){
              MAP[i+1][j].lieu=food;
            }else MAP[i][j].lieu=food;
          }
				}
  		}
		}
  }
  for(i = 1; i < x; i++){ // test pour verifier que la clé est placer sinon on recommence la fonction
    for(j = 1; j < y; j++){
      if(MAP[i][j].num_salle == salle){
        if(MAP[i][j].lieu==food){
          return 1;
        }
      }
    }
  }
  Placer_food();
	return 0;
}

/**
  * \brief Place les pièges
  * \fn int Placer_piege()
  */
int Placer_piege(){
	int nombre_salle_piege = aleat(nombre_salle,9);
    int i,j,salle,taille_salle;
    taille_salle = 0;

  for(i = 1; i < x; i++){
  	for(j = 1; j < y; j++){
    	if(MAP[i][j].num_salle == salle){
    		if(MAP[i][j].lieu == sol){
          taille_salle++;
				}
  		}
		}
  }
	int compteur;

	for(compteur = 0;compteur < nombre_salle_piege; compteur++){

		salle = aleat(1,nombre_salle-2);
	  int pos_piege = aleat(0,taille_salle);
 	 taille_salle = 0;
 	 for(i = 1; i < x; i++){
  		for(j = 1; j < y; j++){
    		if(MAP[i][j].num_salle == salle){
    			if(MAP[i][j].lieu == sol){
    	      		taille_salle++;
    	      		if(taille_salle == pos_piege){
    	      		  if(MAP[i][j+1].lieu==porte){
    	      		    MAP[i][j-1].lieu=piege;
    	      		  }else if(MAP[i][j-1].lieu==porte){
    	      		    MAP[i][j+1].lieu=piege;
    	      		  }else if(MAP[i+1][j].lieu==porte){
    	      		    MAP[i-1][j].lieu=piege;
    	      		  }else if(MAP[i-1][j].lieu==porte){
    	      		    MAP[i+1][j].lieu=medikit;
    	      		  }else MAP[i][j].lieu=piege;
    	      		}
 				}
  			}
		}
	  }
	}
  for(i = 1; i < x; i++){ // test pour verifier que la clé est placer sinon on recommence la fonction
    for(j = 1; j < y; j++){
      if(MAP[i][j].num_salle == salle){
        if(MAP[i][j].lieu==piege){
          return 1;
        }
      }
    }
  }
  Placer_piege();
	return 0;
}
