#include "total.h"

int Charger_Sauvegarde(WINDOW *Err_Win){
	FILE * fic1;
	fic1 = fopen("Save.txt", "r");
	if(fic1 == NULL){
		mvwprintw(Err_Win,4,3,"Il n'existe pas de sauvegarde");
		mvwprintw(Err_Win,5,5,"Une nouvelle partie va être chargé");
		wrefresh(Err_Win);
		sleep(2);
		effacer_fenetre(Err_Win);

		return 'o';
	}
	int i,j;
	char nom_perso[20];
	fscanf(fic1, "%s", nom_perso);
	strcpy(joueur.nom, nom_perso);
	int compteur = 2;
	int entier;
	while(!feof(fic1)){
		if(compteur == 2){
			fscanf(fic1, "%i", &joueur.coordo_x);
		}
		if(compteur == 3){
			fscanf(fic1, "%i", &joueur.coordo_y);
		}
		if(compteur == 4){
			fscanf(fic1, "%i", &entier);
			joueur.etat_avant = entier;
		}
		if(compteur == 5){
			fscanf(fic1, "%i", &joueur.addcle);
		}
		if(compteur == 6){
			fscanf(fic1, "%i", &joueur.STAGE);
		}
		if(compteur == 7){
			fscanf(fic1, "%i", &joueur.SALLE);
		}
		if(compteur == 8){
			fscanf(fic1, "%i", &joueur.LEVEL);
		}
		if(compteur == 9){
			fscanf(fic1, "%i", &joueur.EXP);
		}
		if(compteur == 10){
			fscanf(fic1, "%i", &joueur.HP);
		}
		if(compteur == 11){
			fscanf(fic1, "%i", &joueur.ATT);
		}
		if(compteur == 12){
			fscanf(fic1, "%i", &joueur.DEF);
		}
		if(compteur == 13){
			fscanf(fic1, "%i", &joueur.FOOD);
		}
		if(compteur == 14){
			fscanf(fic1,"%i", &nombre_salle);
		}
		if(compteur == 15){
			fscanf(fic1,"%i", &stage_cle);
		}
		if(compteur == 16){
			fscanf(fic1,"%i", &monstre.coordo_x);
		}
		if(compteur == 17){
			fscanf(fic1,"%i", &monstre.coordo_y);
		}
		if(compteur == 18){
			fscanf(fic1,"%i", &monstre.salle);
		}
		if(compteur == 19){
			fscanf(fic1,"%i", &monstre.EXP);
		}
		if(compteur == 20){
			fscanf(fic1,"%i", &monstre.HP);
		}
		if(compteur == 21){
			fscanf(fic1,"%i", &monstre.ATT);
		}
		if(compteur == 22){
			fscanf(fic1,"%i", &monstre.DEF);
		}
		if(compteur == 23){
			for (i = 0; i < x; i++){
   				for(j = 0; j < y; j++){
   					fscanf(fic1, "%i", &entier);
   					MAP[i][j].lieu = entier;
   					compteur ++;
   				}
   			}
		}
		if (compteur >=24){
			for(i = 0; i < x; i++){
				for(j = 0; j < y; j++){
					if(feof(fic1)){
						break;
					}
					fscanf(fic1,"%i", &i);
					fscanf(fic1,"%i", &j);
					fscanf(fic1,"%i", &entier);
					MAP[i][j].xb = entier;
					fscanf(fic1,"%i",&entier);
					MAP[i][j].yb = entier;
					compteur++;
				}
			}
		}
		compteur++;
	}
	fclose(fic1);
   	return 0;
}
