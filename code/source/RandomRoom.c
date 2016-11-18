#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#define getmaxyx(win,y,x)       (y = getmaxy(win), x = getmaxx(win))

const char * empty = "#";
const char * wall = "+";
const char * floor = ".";

typedef enum element {sol, mur, vide} t_element;
typedef struct cellule {t_element lieu; int position;} t_cellule;
t_cellule MAP[y][x];

int aleat(int min, int max){         //fonction qui retourne un nombre aléatoire entre 2 bornes
    return rand()%(max-min) +min;
}


void fillmap(){                     //fonction qui remplit la map à l'état vide
  int i, j;
  for(i = 0; i < x; i++){
    for(j = 0; j < y; j++){
      MAP[i][j].lieu = vide;
      MAP[i][j].position = 0;
    }
  }
}


void init_room(){                   //fonction qui initialise une salle de taille aléatoire à un endroit aléatoire.
  int i, j;
  int k = 0;
  int nb_salle, lg_mur, posx, posy, lg_mur_horiz, lg_mur_vert;
  lg_mur_horiz = aleat(10,20);
  lg_mur_vert= aleat(10,20);
  posy = aleat(0,y);
  posx = aleat(0,x);

  j = posx;
  for(i = posy; i < lg_mur_horiz; i++){   //On place le mur du haut
  MAP[i][j].lieu = mur;
  MAP[i][j].position = 0;
  }
  for(j = posx; j < lg_mur_vert; j--){     //...de droite
  MAP[i][j].lieu = mur;
  MAP[i][j].position = 0;
  }
  for(i = posy; i < lg_mur_horiz; i--){   //...du bas
  MAP[i][j].lieu = mur;
  MAP[i][j].position = 0;
  }
  for(j = posx; j < lg_mur_vert; j++){     //...de gauche
  MAP[i][j].lieu = mur;
  MAP[i][j].position = 0;
  }

  for(i = posy + 1; i < lg_mur_horiz - 1; i++){   //on place le sol dans la salle
    for(j = posx - 1; j < lg_mur_vert - 1; j++){
      MAP[i][j].lieu = sol;
      MAP[i][j].position = 0;
    }
  }


}
