//#include "total.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef enum element {vide, mur, sol, porte, couloir, personnage, uplevel, arriver, cle} t_element;

typedef struct cellule {t_element lieu; int position; int relie; int num_salle;} t_cellule;

typedef struct joueur {char nom[20];int coordo_x;int coordo_y;t_element etat_avant;int addcle;int STAGE;int SALLE;int LEVEL;int EXP;int HP;int ATT;int DEF;int FOOD;} t_joueur;
t_joueur joueur;

#define x 30
#define y 89
t_cellule MAP[x][y];

int main(){
	FILE * fic1;
	fic1 = fopen("Save.txt", "r");
	if(fic1 == NULL){
		printf("vgjhbk");
	}
	int i,j;
	fscanf(fic1, "%s", &joueur.nom);
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
			fscanf(fic1, "%i", &joueur.etat_avant);
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
	printf("\n ejhsdbj \n");
	printf(" nom du joueur : %s \n", joueur.nom);
	printf(" positionx du joueur : %i \n", joueur.coordo_x);
	printf(" positiony du joueur : %i \n", joueur.coordo_y);
	printf(" etatav du joueur : %i \n", joueur.etat_avant);
	printf(" cle du joueur : %i \n", joueur.addcle);
	printf(" STAGE du joueur : %i \n", joueur.STAGE);
	printf(" SALLE du joueur : %i \n", joueur.SALLE);
	printf(" LEVEL du joueur : %i \n", joueur.LEVEL);
	printf(" EXP du joueur : %i \n", joueur.EXP);
	printf(" HP du joueur : %i \n", joueur.HP);
	printf(" ATT du joueur : %i \n", joueur.ATT);
	printf(" DEF du joueur : %i \n", joueur.DEF);
	printf(" FOOD du joueur : %i \n", joueur.FOOD);
	printf("\n");
	for (i = 0; i < x; i++){
   		for(j = 0; j < y; j++){
   			printf("%i ", MAP[i][j].lieu);
   		}
   		printf("\n");
   }
   printf("\n");
   printf("compteur : %i\n", compteur);
}