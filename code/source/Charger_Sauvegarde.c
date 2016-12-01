#include "total.h"

int Charger_Sauvegarde(){
	FILE * fic1;
	fic1 = fopen("Save.txt", "r");
	if(fic1 == NULL){
		WINDOW *Err_Win;
		int startxErr, startyErr, widthErr, heightErr;
		heightErr = LINES*0.33;
		widthErr = COLS*0.33;
		startxErr = COLS*0.33;
		startyErr = LINES*0.33;
		Err_Win=create_newwin(heightErr,widthErr,startyErr,startxErr,"Erreur");
		mvwprintw(Err_Win,5,widthErr*0.33,"Il n'existe pas de sauvegarde");
		mvwprintw(Err_Win,6,widthErr*0.30,"Une nouvelle partie va être chargé");
		wrefresh(Err_Win);
		sleep(2);
		effacer_fenetre(Err_Win);
		wborder(Err_Win, ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ');
		wrefresh(Err_Win);
		delwin(Err_Win);
		return KEY_RIGHT;
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
			for (i = 0; i < x; i++){
   				for(j = 0; j < y; j++){
   					fscanf(fic1, "%i", &entier);
   					MAP[i][j].lieu = entier;
   					compteur ++;
   				}
   			}
		}
		compteur++;
		if(compteur == 2685){
			break;
		}		
	}
	fclose(fic1);
   	return 0;
}
	
