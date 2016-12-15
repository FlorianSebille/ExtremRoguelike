/**
 * \file sauvegarde.c
 * \brief Fichier contenant la fontion qui créer une sauvegarde
 * \author LARDY Anthony
 * \version 1.0.1
 */

#include "total.h"



/**
  * \brief Création d'une sauvegarde
  * \fn addsauv()
  */

void addsauv(){
	FILE * fic1;
	int entier;
	int i,j;
	char nom_perso[20];
	fic1 = fopen("Save.txt", "w");		/*!< Créer un fichier Save.txt. */
	/** Copie toutes les statistiques du joueur */
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
	/** Copie les informations générales du jeu */
	entier = nombre_salle;
	fprintf(fic1,"%i ", entier);
	entier = stage_cle;
	fprintf(fic1,"%i ", entier);

	/** Copie les statistiques du monstre */
	entier = monstre.coordo_x;
	fprintf(fic1,"%i ", entier);
	entier = monstre.coordo_y;
	fprintf(fic1,"%i ", entier);
	entier = monstre.salle;
	fprintf(fic1,"%i ", entier);
	entier = monstre.EXP;
	fprintf(fic1,"%i ", entier);
	entier = monstre.HP;
	fprintf(fic1,"%i ", entier);
	entier = monstre.ATT;
	fprintf(fic1,"%i ", entier);
	entier = monstre.DEF;
	fprintf(fic1,"%i ", entier);
	fprintf(fic1,"\n\n");

	/** Parcours la carte et copie le type de lieu de chaque cellule */
	for (i = 0; i < x; i++){
   		for(j = 0; j < y; j++){
   			entier = MAP[i][j].lieu;
   			fprintf(fic1,"%i ", entier);
   		}
   		fprintf(fic1,"\n");
   	}
   	fprintf(fic1,"\n");
	/** Parcours la carte et copie le num_salle de chaque cellule */
	for (i = 0; i < x; i++){
   		for(j = 0; j < y; j++){
   			entier = MAP[i][j].num_salle;
   			fprintf(fic1,"%i ", entier);
   		}
   		fprintf(fic1,"\n");
   	}
   	fprintf(fic1,"\n");
   	/** Parcours la carte et copie les coordonées de la porte ainsi que celle avec qui elle est reliée */
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
   	
	fclose(fic1);		/*!< Fermeture du fichier Save.txt. */
}
