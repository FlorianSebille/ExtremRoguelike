#include "total.h"

void init_file(){
	tete = NULL;
	queue = NULL;
}

int file_vide(void){
	return(tete == NULL);
}

void ajouter(int l, int c){
	t_elemfile*nouv;
	nouv = malloc(sizeof(t_elemfile));
	nouv->nombre.ligne=l;
	nouv->nombre.colonne=c;
	nouv->suivant=NULL;
	if(file_vide())tete=nouv;
	else queue->suivant=nouv;
	queue=nouv;
}

void retirer(int*l, int*c){
	t_elemfile*premier;
	if(!file_vide()){
		premier=tete;
		*l=premier->nombre.ligne;
		*c=premier->nombre.colonne;
		tete=premier->suivant;
		free(premier);
	}
}

void queue_file(int*l, int*c){
	if(queue != NULL){
		*l = queue->nombre.ligne;
		*l = queue->nombre.colonne;
	}

}
