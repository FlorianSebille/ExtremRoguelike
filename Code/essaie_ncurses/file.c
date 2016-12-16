
/**
 * \file file.c
 * \brief Programme regroupant les primitives nécessaires à l'utilisation d'une file
 * \author TROTTIER Artur
 * \version 1.0.1
 */

 #include <stdio.h>
 #include <string.h>
 #include <math.h>
 #include <curses.h>
 #include <stdlib.h>
 #include <time.h>
 #include <unistd.h>
 #include <ncurses.h>
 #include "file.h"

void init_file(){
	tete = NULL;
	queue = NULL;
}

int file_vide(void){
	return(tete == NULL);
}

void ajouter(t_coord coord){
	t_elemfile*nouv;
	nouv = malloc(sizeof(t_elemfile));
	nouv->nombre.ligne=coord.ligne;
	nouv->nombre.colonne=coord.colonne;
	nouv->suivant=NULL;
	if(file_vide())tete=nouv;
	else queue->suivant=nouv;
	queue=nouv;
}

void retirer(t_coord*coord){
	t_elemfile*premier;
	if(!file_vide()){
		premier=tete;
		coord->ligne=premier->nombre.ligne;
		coord->colonne=premier->nombre.colonne;
		tete=premier->suivant;
		free(premier);
	}
}

void queue_file(t_coord*coord){
	if(queue != NULL){
		coord->ligne = queue->nombre.ligne;
		coord->colonne = queue->nombre.colonne;
	}
}

void file_supprimer(){
    t_elemfile * tmp;
    while (tete != NULL) {
        tmp = tete;
        tete = tete->suivant;
        free(tmp);
    }
}
