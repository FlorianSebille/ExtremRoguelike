#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define x 30
#define y 89

typedef enum {vide, mur, sol, porte, couloir, personnage, uplevel, arriver, cle, food, piege, medikit, mechant} t_element;
typedef struct {t_element lieu; int position; int relie; int xb;int yb;int num_salle;int presence;} t_cellule;

t_cellule MAP[x][y];

void fillmap(){

  int i, j;
  for(i = 0; i < x; i++){
    for(j = 0; j < y; j++){
      MAP[i][j].lieu = vide;
      MAP[i][j].position = 0;
      MAP[i][j].relie = 0;
    }
  }
}

int main(){
  int vide = 0, position = 0, relie = 0;
  int i, j;
  fillmap();
  for(i = 0; i < x; i++){
    for(j = 0; j < y; j++){
      if(MAP[i][j].lieu != vide) vide = 1;
      if(MAP[i][j].position != 0) position = 1;
      if(MAP[i][j].relie != 0) relie= = 1;
    }
  }
  if(vide == 0)printf("Test lieu réussi \n");
  else printf("Test lieu echec \n");
  if(position == 0)printf("Test position réussi \n");
  else printf("Test position echec \n");
  if(relie == 0)printf("Test relie réussi \n");
  else printf("Test relie echec \n");
}
