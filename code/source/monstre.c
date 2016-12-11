#include "total.h"


void init_presence(WINDOW *fenetre){
	int i,max_i,j,max_j,dimension_carre;
	getmaxyx(fenetre,max_i,max_j);
	for(i = 1; i < max_i -1; i++){
		for(j = 1;j < max_j -1; j++){
			MAP[i][j].presence=0;
		}
	}
	for(dimension_carre = 1;dimension_carre < 10;dimension_carre++){
		for(i = joueur.coordo_x - dimension_carre; i < joueur.coordo_x + dimension_carre; i++){
			for(j = joueur.coordo_y - dimension_carre;j < joueur.coordo_y + dimension_carre; j++){
				if(MAP[i][j].presence == 0){
					MAP[i][j].presence = 10 - dimension_carre;
				}
			}
		}
	}		
}

int calcul_presence(int ligne, int colonne){
	int i,j;
	int somme = 0;
	for(i=ligne-1;i<=ligne+1;i++){
		for(j=colonne-1;j<=colonne+1;j++){
			somme=somme+MAP[i][j].presence;	
		}
	}
	return somme;
}


void depl_monstre(WINDOW *fenetre){
	/*if(joueur.SALLE == monstre.salle){
		int i,max_i,j,max_j,futurx,futury;
		int maxsomme = 0;
		getmaxyx(fenetre,max_i,max_j);
		init_presence(fenetre);
		for(i = joueur.coordo_x - 1; i < joueur.coordo_x + 1; i++){
			for(j = joueur.coordo_y - 1;j < joueur.coordo_y + 1; j++){
				if(maxsomme <= calcul_presence(i, j) && MAP[i][j].lieu == sol){
					maxsomme = calcul_presence(i, j);
					futurx = i;
					futury = j;
				}
			}
		}
		if(MAP[i-1][j].lieu == personnage || MAP[i+1][j].lieu == personnage || MAP[i][j-1].lieu == personnage || MAP[i][j+1].lieu == personnage){

		}else{
			MAP[monstre.coordo_x][monstre.coordo_y].lieu = sol;
			monstre.coordo_x = i;
			monstre.coordo_y = j;
			MAP[i][j].lieu = mechant;
		}
		if(MAP[i][j].lieu != mur){
			MAP[monstre.coordo_x][monstre.coordo_y].lieu = sol;
			monstre.coordo_x = i;
			monstre.coordo_y = j;
			MAP[i][j].lieu = mechant;
		}	
	}*/
	int futury,futurx;
	do{
		int	Depl_aleatoire = aleat(0,5);
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