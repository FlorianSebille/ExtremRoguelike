#include "total.h"

void addsauv(){
	FILE * fic1;
	int entier;
	int i,j;
	char nom_perso[20];
	fic1 = fopen("Save.txt", "w");
	strcpy(nom_perso, joueur.nom);
	fprintf(fic1,"%s ", nom_perso);
	entier = joueur.coordo_x;
	fprintf(fic1,"%i ", entier);
	entier = joueur.coordo_y;
	fprintf(fic1,"%i ", entier);
	entier = joueur.etat_avant;
	fprintf(fic1,"%i ", entier);
	entier = joueur.addcle; 
	fprintf(fic1,"%i ", entier);
	entier = joueur.STAGE;
	fprintf(fic1,"%i ", entier);
	entier = joueur.SALLE;
	fprintf(fic1,"%i ", entier);
	entier = joueur.LEVEL;
	fprintf(fic1,"%i ", entier);
	entier = joueur.EXP;
	fprintf(fic1,"%i ", entier);
	entier = joueur.HP;
	fprintf(fic1,"%i ", entier);
	entier = joueur.ATT;
	fprintf(fic1,"%i ", entier);
	entier = joueur.DEF;
	fprintf(fic1,"%i ", entier);
	entier = joueur.FOOD;
	fprintf(fic1,"%i ", entier);
	entier = nombre_salle;
	fprintf(fic1,"%i ", entier);
	entier = stage_cle;
	fprintf(fic1,"%i ", entier);
	fprintf(fic1,"\n\n");
	for (i = 0; i < x; i++){
   		for(j = 0; j < y; j++){
   			entier = MAP[i][j].lieu;
   			fprintf(fic1,"%i ", entier);
   		}
   		fprintf(fic1,"\n");
   	}
   	fprintf(fic1,"\n");
   	for(i = 0; i < x; i++){
   		for(j = 0; j < y; j++){
   			if(MAP[i][j].xb != 0 && MAP[i][j].yb != 0){
   				fprintf(fic1,"%i %i      ",i ,j);
   				entier = MAP[i][j].xb;
   				fprintf(fic1,"%i ",entier);
   				entier = MAP[i][j].yb;
   				fprintf(fic1,"%i ",entier);
   				fprintf(fic1,"\n");
   			}
   		}
   	}
	fclose(fic1);
}
